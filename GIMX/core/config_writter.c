/*
 Copyright (c) 2011 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#include <string.h>
#include "config.h"
#include "config_reader.h"
#include <xml_defs.h>
#include <gimxinput/include/ginput.h>
#include "calibration.h"
#include <libxml/xmlreader.h>
#include <libxml/xmlwriter.h>
#include <limits.h>

#include "../directories.h"
#include "gimx.h"
#include <controller.h>

/*
 * These variables are used to read the configuration.
 */
static unsigned int r_controller_id;
static unsigned int r_profile_id;
static e_device_type r_device_type;
static int r_device_id;
static char r_device_name[128];

static int ProcessEventElement(xmlNode * a_node)
{
  int ret = 0;
  char* type;
  char* event_id;
  char multiplier[32];
  char dead_zone[32];
  char exponent[32];
  char* shape;
  s_mouse_cal* mcal = cal_get_mouse(r_device_id, r_profile_id);

  type = (char*) xmlGetProp(a_node, (xmlChar*) X_ATTR_TYPE);

  if(!type)
  {
    ret = -1;
  }
  else
  {
    if (!strncmp(type, X_ATTR_VALUE_AXIS, strlen(X_ATTR_VALUE_AXIS)))
    {
      event_id = (char*) xmlGetProp(a_node, (xmlChar*) X_ATTR_ID);

      if(!event_id)
      {
        ret = -1;
      }
      else
      {
        if (!strncmp(event_id, MOUSE_AXIS_X, sizeof(MOUSE_AXIS_X)))
        {
          if(mcal->mx)
          {
            sprintf(multiplier, "%.2f", *mcal->mx);
            xmlSetProp(a_node, BAD_CAST X_ATTR_MULTIPLIER, BAD_CAST (const char*) multiplier);
          }

          if(mcal->dzx)
          {
            sprintf(dead_zone, "%d", *mcal->dzx);
            xmlSetProp(a_node, BAD_CAST X_ATTR_DEADZONE, BAD_CAST (const char*) dead_zone);
          }

          if(mcal->ex)
          {
            sprintf(exponent, "%.2f", *mcal->ex);
            xmlSetProp(a_node, BAD_CAST X_ATTR_EXPONENT, BAD_CAST (const char*) exponent);
          }

          if(mcal->dzs)
          {
            if(*mcal->dzs == E_SHAPE_RECTANGLE)
            {
              shape = X_ATTR_VALUE_RECTANGLE;
            }
            else
            {
              shape = X_ATTR_VALUE_CIRCLE;
            }
            xmlSetProp(a_node, BAD_CAST X_ATTR_SHAPE, BAD_CAST (const char*) shape);
          }
        }
        else if (!strncmp(event_id, MOUSE_AXIS_Y, sizeof(MOUSE_AXIS_Y)))
        {
          if(mcal->my)
          {
            sprintf(multiplier, "%.2f", *mcal->my);
            xmlSetProp(a_node, BAD_CAST X_ATTR_MULTIPLIER, BAD_CAST (const char*) multiplier);
          }

          if(mcal->dzy)
          {
            sprintf(dead_zone, "%d", *mcal->dzy);
            xmlSetProp(a_node, BAD_CAST X_ATTR_DEADZONE, BAD_CAST (const char*) dead_zone);
          }

          if(mcal->ey)
          {
            sprintf(exponent, "%.2f", *mcal->ey);
            xmlSetProp(a_node, BAD_CAST X_ATTR_EXPONENT, BAD_CAST (const char*) exponent);
          }

          if(mcal->dzs)
          {
            if(*mcal->dzs == E_SHAPE_RECTANGLE)
            {
              shape = X_ATTR_VALUE_RECTANGLE;
            }
            else
            {
              shape = X_ATTR_VALUE_CIRCLE;
            }
            xmlSetProp(a_node, BAD_CAST X_ATTR_SHAPE, BAD_CAST (const char*) shape);
          }
        }

        xmlFree(event_id);
      }
    }

    xmlFree(type);
  }

  return ret;
}

static int ProcessDeviceElement(xmlNode * a_node)
{
  int ret = 0;
  char* prop;
  int i;
  char* type;

  type = (char*) xmlGetProp(a_node, (xmlChar*) X_ATTR_TYPE);

  if (!strncmp(type, X_ATTR_VALUE_MOUSE, strlen(X_ATTR_VALUE_MOUSE)))
  {
    r_device_type = E_DEVICE_TYPE_MOUSE;

    if(ret != -1)
    {
      ret = GetIntProp(a_node, X_ATTR_ID, &r_device_id);

      prop = (char*) xmlGetProp(a_node, (xmlChar*) X_ATTR_NAME);
      if(prop)
      {
        strncpy(r_device_name, prop, sizeof(r_device_name));
      }
      xmlFree(prop);

      if(ginput_get_mk_mode() == GE_MK_MODE_SINGLE_INPUT)
      {
        r_device_id = 0;
      }
      else
      {
        for (i = 0; i < MAX_DEVICES && ginput_mouse_name(i); ++i)
        {
          if (!strcmp(r_device_name, ginput_mouse_name(i)))
          {
            if (r_device_id == ginput_mouse_virtual_id(i))
            {
              r_device_id = i;
              break;
            }
          }
        }
        if(i == MAX_DEVICES || !ginput_mouse_name(i))
        {
          r_device_id = -1;
        }
      }
    }
  }

  return ret;
}

static int ProcessAxisElement(xmlNode * a_node)
{
  int ret = 0;
  xmlNode* cur_node = NULL;

  for (cur_node = a_node->children; cur_node && ret != -1; cur_node = cur_node->next)
  {
    if (cur_node->type == XML_ELEMENT_NODE)
    {
      if (xmlStrEqual(cur_node->name, (xmlChar*) X_NODE_DEVICE))
      {
        ret = ProcessDeviceElement(cur_node);
        break;
      }
      else
      {
        gwarn("bad element name: %s", cur_node->name);
        ret = -1;
      }
    }
  }

  if (!cur_node)
  {
    gwarn("missing device element");
    ret = -1;
  }

  if(r_device_type != E_DEVICE_TYPE_MOUSE || r_device_id < 0)
  {
    return ret;
  }

  for (cur_node = cur_node->next; cur_node && ret != -1; cur_node = cur_node->next)
  {
    if (cur_node->type == XML_ELEMENT_NODE)
    {
      if (xmlStrEqual(cur_node->name, (xmlChar*) X_NODE_EVENT))
      {
        ret = ProcessEventElement(cur_node);
        break;
      }
      else
      {
        gwarn("bad element name: %s", cur_node->name);
        ret = -1;
      }
    }
  }

  if (!cur_node)
  {
    gwarn("missing event element");
    ret = -1;
  }

  return ret;
}

static int ProcessAxisMapElement(xmlNode * a_node)
{
  int ret = 0;
  xmlNode* cur_node = NULL;

  for (cur_node = a_node->children; cur_node && ret != -1; cur_node = cur_node->next)
  {
    if (cur_node->type == XML_ELEMENT_NODE)
    {
      if (xmlStrEqual(cur_node->name, (xmlChar*) X_NODE_AXIS))
      {
        ret = ProcessAxisElement(cur_node);
      }
      else
      {
        gwarn("bad element name: %s", cur_node->name);
        ret = -1;
      }
    }
  }
  return ret;
}

static int ProcessConfigurationElement(xmlNode * a_node)
{
  int ret = 0;
  xmlNode* cur_node = NULL;

  ret = GetUnsignedIntProp(a_node, X_ATTR_ID, &r_profile_id);

  if(ret != -1)
  {
    r_profile_id--;

    if (r_profile_id >= MAX_PROFILES)
    {
      gwarn("bad profile id: %d\n", r_profile_id);
      ret = -1;
    }
  }

  cur_node = a_node->children;

  for (cur_node = cur_node->next; cur_node && ret != -1; cur_node = cur_node->next)
  {
    if (cur_node->type == XML_ELEMENT_NODE)
    {
      if (xmlStrEqual(cur_node->name, (xmlChar*) X_NODE_AXIS_MAP))
      {
        ret = ProcessAxisMapElement(cur_node);
        break;
      }
    }
  }

  if (!cur_node)
  {
    gwarn("missing axis_map element");
    ret = -1;
  }

  return ret;
}

static int ProcessControllerElement(xmlNode * a_node)
{
  xmlNode* cur_node = NULL;
  int ret = 0;

  ret = GetUnsignedIntProp(a_node, X_ATTR_ID, &r_controller_id);

  if(ret != -1)
  {
    r_controller_id--;

    if (r_controller_id >= MAX_CONTROLLERS)
    {
      gwarn("bad controller id: %d\n", r_controller_id);
      ret = -1;
    }
  }

  for (cur_node = a_node->children; cur_node && ret != -1; cur_node = cur_node->next)
  {
    if (cur_node->type == XML_ELEMENT_NODE)
    {
      if (xmlStrEqual(cur_node->name, (xmlChar*) X_NODE_CONFIGURATION))
      {
        ret = ProcessConfigurationElement(cur_node);
      }
      else
      {
        ret = -1;
        gwarn("bad element name: %s\n", cur_node->name);
      }
    }
  }
  return ret;
}

static int ProcessRootElement(xmlNode * a_node)
{
  xmlNode *cur_node = NULL;
  int ret = 0;

  if (a_node->type == XML_ELEMENT_NODE)
  {
    if (xmlStrEqual(a_node->name, (xmlChar*) X_NODE_ROOT))
    {
      for (cur_node = a_node->children; cur_node && ret != -1; cur_node = cur_node->next)
      {
        if (cur_node->type == XML_ELEMENT_NODE)
        {
          if (xmlStrEqual(cur_node->name, (xmlChar*) X_NODE_CONTROLLER))
          {
            ret = ProcessControllerElement(cur_node);
          }
          else
          {
            ret = -1;
            gwarn("bad element name: %s\n", cur_node->name);
          }
        }
      }
    }
    else
    {
      ret = -1;
      gwarn("bad element name: %s\n", a_node->name);
    }
  }
  return ret;
}

/*
 * This function modifies a config file according to the calibrated values.
 */
int cfgw_modify_file(char* file)
{
  xmlDoc *doc = NULL;
  xmlNode *root_element = NULL;
  int ret = 0;
  char file_path[PATH_MAX];

  snprintf(file_path, sizeof(file_path), "%s%s%s%s", gimx_params.homedir, GIMX_DIR, CONFIG_DIR, file);

  /*
   * this initialize the library and check potential ABI mismatches
   * between the version it was compiled for and the actual shared
   * library used.
   */
  LIBXML_TEST_VERSION

  /*parse the file and get the DOM */
  doc = xmlReadFile(file_path, NULL, 0);

#ifdef WIN32
  if(!xmlFree) xmlMemGet(&xmlFree,&xmlMalloc,&xmlRealloc,NULL);
#endif

  if (doc != NULL)
  {
    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);

    if(root_element != NULL)
    {
      ret = ProcessRootElement(root_element);
    }
    else
    {
      ret = -1;
      gwarn("error: no root element\n");
    }

    if(ret != -1)
    {
      xmlSaveFormatFileEnc(file_path, doc, "UTF-8", 1);
    }
  }
  else
  {
    ret = -1;
    gwarn("error: could not parse file %s\n", file_path);
  }

  /*free the document */
  xmlFreeDoc(doc);

  return ret;
}
