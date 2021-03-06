/*
 Copyright (c) 2010 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#ifndef CONFIGMAIN_H
#define CONFIGMAIN_H

//(*Headers(configFrame)
#include <wx/grid.h>
#include <wx/spinctrl.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

#include <gimxconfigeditor/include/EventCatcher.h>
#include <gimxconfigeditor/include/ConfigurationFile.h>

class configFrame: public wxFrame
{
    public:

        configFrame(wxString file,wxWindow* parent,wxWindowID id = -1);
        virtual ~configFrame();

        void reset_buttons();
        void save_current();
        void load_current();
        void refresh_gui();

    private:

        //(*Handlers(configFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuItemNew(wxCommandEvent& event);
        void OnButtonTabModifyClick(wxCommandEvent& event);
        void OnButtonAddPanelButton(wxCommandEvent& event);
        void OnEventTypeSelectPanelAxis(wxCommandEvent& event);
        void OnAxisTabBufferSizeText(wxCommandEvent& event);
        void OnButtonAddPanelAxis(wxCommandEvent& event);
        void OnButtonRemovePanelButton(wxCommandEvent& event);
        void OnButtonRemovePanelAxis(wxCommandEvent& event);
        void OnButtonTabEventTypeSelect(wxCommandEvent& event);
        void OnChoice6Select(wxCommandEvent& event);
        void OnChoice6Select1(wxCommandEvent& event);
        void OnButtonAutoDetectClick(wxCommandEvent& event);
        void OnAxisTabShape5Select(wxCommandEvent& event);
        void OnAxisTabShape7Select(wxCommandEvent& event);
        void OnAxisTabShape8Select(wxCommandEvent& event);
        void OnCheckBox2Click(wxCommandEvent& event);
        void OnCheckBoxSwitchBackClick(wxCommandEvent& event);
        void OnButtonTabAutoDetectClick(wxCommandEvent& event);
        void OnAxisTabAutoDetectClick(wxCommandEvent& event);
        void OnButtonDeleteClick(wxCommandEvent& event);
        void OnMenuOpen(wxCommandEvent& event);
        void OnMenuItemExpert(wxCommandEvent& event);
        void OnMenuSave(wxCommandEvent& event);
        void OnMenuSaveAs(wxCommandEvent& event);
        void OnButtonModifyButton(wxCommandEvent& event);
        void OnButtonModifyAxis(wxCommandEvent& event);
        void OnAxisTabShapeSelect(wxCommandEvent& event);
        void OnMenuItemCopyConfiguration(wxCommandEvent& event);
        void OnMenuItemPasteConfiguration(wxCommandEvent& event);
        void OnMenuItemCopyController(wxCommandEvent& event);
        void OnMenuItemPasteController(wxCommandEvent& event);
        void OnButtonDeleteTrigger(wxCommandEvent& event);
        void OnMenuReplaceMouse(wxCommandEvent& event);
        void OnMenuReplaceKeyboard(wxCommandEvent& event);
        void OnMenuItemReplaceMouseDPI(wxCommandEvent& event);
        void OnMenuReplaceMouseDPI(wxCommandEvent& event);
        void OnMenuSetMouseDPI(wxCommandEvent& event);
        void OnMenuMultipleMK(wxCommandEvent& event);
        void OnTextCtrl(wxCommandEvent& event);
        void OnMenuAutoBindControls(wxCommandEvent& event);
        void OnMenuItemController(wxCommandEvent& event);
        void OnMenuItemConfiguration(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnIntensityAutoDetectClick(wxCommandEvent& event);
        void OnIntensityDeadZoneChange(wxSpinEvent& event);
        void OnIntensityModifyClick(wxCommandEvent& event);
        void OnIntensityAddClick(wxCommandEvent& event);
        void OnIntensityRemoveClick(wxCommandEvent& event);
        void OnIntensityAxisSelect(wxCommandEvent& event);
        void OnMouseOptionsAutoDetectClick(wxCommandEvent& event);
        void OnMouseOptionsTriggerAutoDetectClick(wxCommandEvent& event);
        void OnMouseOptionsAddClick(wxCommandEvent& event);
        void OnMouseOptionsRemoveClick(wxCommandEvent& event);
        void OnMouseOptionsModifyClick(wxCommandEvent& event);
        void OnMenuOpenConfigDirectory(wxCommandEvent& event);
        void OnMenuTypeItemSelected(wxCommandEvent& event);
        void OnButtonTabButtonIdSelect(wxCommandEvent& event);
        void OnMenuItemWindowEventsSelected(wxCommandEvent& event);
        void OnJoystickCorrectionsAddClick(wxCommandEvent& event);
        void OnJoystickCorrectionsRemoveClick(wxCommandEvent& event);
        void OnJoystickCorrectionsModifyClick(wxCommandEvent& event);
        void OnJoystickCorrectionsAutoDetectClick(wxCommandEvent& event);
        void OnButtonForceFeedbackAutoDetect(wxCommandEvent& event);
        void OnButtonFFBTweaksDelete(wxCommandEvent& event);
        void OnAxisTabAxisIdSelect(wxCommandEvent& event);
        //*)
        void OnClose(wxCloseEvent& event);
        void DeleteSelectedRows(wxGrid* grid);
        void DeleteLinkedRows(wxGrid* grid, int row);
        void replaceDevice(wxString wx_device_type);
        void auto_detect(wxStaticText* device_type, string* name, wxStaticText* device_name, wxStaticText* device_id, wxString event_type, wxStaticText* event_id);
        void updateButtonConfigurations();
        void updateAxisConfigurations();
        void updateIntensityConfigurations(Intensity* oldI, Intensity* newI);
        void updateMouseOptionsConfigurations(MouseOptions* oldM, MouseOptions* newM);
        wxString isAlreadyUsed(wxString device_type, wxString device_name, wxString device_id, wxString event_type, wxString event_id, int gridIndex1, int gridIndex2, int gridIndex3);
        bool isMouseOptionsDefined(wxString device_name, wxString device_id, int gridIndex);
        bool isJoystickCorrectionDefined(wxString device_name, wxString device_id, wxString axis_id, int gridIndex);
        void readLabels();
        string reverseTranslate(string str);
        void fillButtonAxisChoice();
        void fillAxisAxisChoice();
        void fillButtonChoice();
        void fillIntensityAxisChoice();
        void fillChoices();
        void LoadControllerType();
        pair<Device, Event> selectEvent();
        void addJoystickCorrection();
        void openConfiguration(const wxString& directory, const wxString& file);
        bool save(const wxString& directory, const wxString& file);
        void checkSave();

        //(*Identifiers(configFrame)
        static const long ID_STATICTEXT35;
        static const long ID_STATICTEXT27;
        static const long ID_STATICTEXT36;
        static const long ID_STATICTEXT37;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE5;
        static const long ID_CHECKBOX1;
        static const long ID_STATICTEXT28;
        static const long ID_SPINCTRL5;
        static const long ID_STATICLINE6;
        static const long ID_BUTTON10;
        static const long ID_PANEL4;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT9;
        static const long ID_BUTTON11;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT10;
        static const long ID_CHOICE3;
        static const long ID_STATICLINE2;
        static const long ID_STATICTEXT26;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL11;
        static const long ID_GRID4;
        static const long ID_BUTTON12;
        static const long ID_BUTTON13;
        static const long ID_BUTTON14;
        static const long ID_PANEL5;
        static const long ID_STATICTEXT55;
        static const long ID_CHOICE6;
        static const long ID_STATICLINE4;
        static const long ID_STATICTEXT45;
        static const long ID_STATICTEXT46;
        static const long ID_STATICTEXT47;
        static const long ID_STATICTEXT52;
        static const long ID_STATICTEXT73;
        static const long ID_BUTTON19;
        static const long ID_STATICLINE3;
        static const long ID_STATICTEXT74;
        static const long ID_STATICTEXT53;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT54;
        static const long ID_CHOICE9;
        static const long ID_SPINCTRL6;
        static const long ID_CHOICE2;
        static const long ID_SPINCTRL7;
        static const long ID_GRID3;
        static const long ID_BUTTON21;
        static const long ID_BUTTON22;
        static const long ID_BUTTON23;
        static const long ID_PANEL6;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT24;
        static const long ID_STATICTEXT19;
        static const long ID_BUTTON15;
        static const long ID_STATICLINE14;
        static const long ID_STATICTEXT23;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_GRID5;
        static const long ID_BUTTON16;
        static const long ID_BUTTON17;
        static const long ID_BUTTON18;
        static const long ID_PANEL7;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT25;
        static const long ID_STATICTEXT49;
        static const long ID_BUTTON20;
        static const long ID_STATICLINE13;
        static const long ID_STATICTEXT31;
        static const long ID_STATICTEXT50;
        static const long ID_STATICTEXT29;
        static const long ID_STATICTEXT33;
        static const long ID_STATICTEXT48;
        static const long ID_CHECKBOX2;
        static const long ID_SPINCTRL4;
        static const long ID_SPINCTRL3;
        static const long ID_SPINCTRL2;
        static const long ID_SPINCTRL1;
        static const long ID_STATICLINE15;
        static const long ID_BUTTON24;
        static const long ID_PANEL8;
        static const long ID_NOTEBOOK2;
        static const long ID_PANEL1;
        static const long ID_STATICTEXT38;
        static const long ID_STATICTEXT30;
        static const long ID_STATICTEXT39;
        static const long ID_CHOICE4;
        static const long ID_STATICTEXT40;
        static const long ID_STATICTEXT2;
        static const long ID_BUTTON8;
        static const long ID_STATICLINE8;
        static const long ID_STATICTEXT7;
        static const long ID_CHOICE5;
        static const long ID_STATICLINE9;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICLINE10;
        static const long ID_STATICTEXT34;
        static const long ID_COMBOBOX1;
        static const long ID_GRID1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON6;
        static const long ID_BUTTON2;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT41;
        static const long ID_STATICTEXT32;
        static const long ID_STATICTEXT42;
        static const long ID_CHOICE7;
        static const long ID_STATICTEXT43;
        static const long ID_STATICTEXT21;
        static const long ID_BUTTON9;
        static const long ID_STATICLINE11;
        static const long ID_STATICTEXT16;
        static const long ID_CHOICE8;
        static const long ID_STATICLINE7;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT22;
        static const long ID_TEXTCTRL8;
        static const long ID_TEXTCTRL9;
        static const long ID_TEXTCTRL10;
        static const long ID_CHOICE1;
        static const long ID_STATICLINE12;
        static const long ID_STATICTEXT44;
        static const long ID_COMBOBOX2;
        static const long ID_GRID2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON7;
        static const long ID_BUTTON5;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK1;
        static const long idMenuNew;
        static const long idMenuOpen;
        static const long idMenuSave;
        static const long idMenuSaveAs;
        static const long ID_MENUITEM28;
        static const long idMenuQuit;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM18;
        static const long ID_MENUITEM17;
        static const long ID_MENUITEM19;
        static const long ID_MENUITEM23;
        static const long ID_MENUITEM20;
        static const long ID_MENUITEM22;
        static const long ID_MENUITEM21;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEMDS4;
        static const long ID_MENUITEMDS3;
        static const long ID_MENUITEMDS2;
        static const long ID_MENUITEMXONE;
        static const long ID_MENUITEM360;
        static const long ID_MENUITEMXBOX;
        static const long ID_MENUITEMJS;
        static const long ID_MENUITEMT300RSPS4;
        static const long ID_MENUITEMG27PS3;
        static const long ID_MENUITEMG29PS4;
        static const long ID_MENUITEMDFPS2;
        static const long ID_MENUITEMDFPPS2;
        static const long ID_MENUITEMGTFPS2;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM9;
        static const long ID_MENUITEM10;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM13;
        static const long ID_MENUITEM14;
        static const long ID_MENUITEM15;
        static const long ID_MENUITEM16;
        static const long ID_MENUITEM24;
        static const long ID_MENUITEM29;
        static const long ID_MENUITEM25;
        static const long ID_MENUITEM27;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(configFrame)
        wxMenu* MenuType;
        wxButton* MouseOptionsAutoDetect;
        wxStaticText* StaticText1;
        wxSpinCtrl* ProfileTriggerDelay;
        wxButton* IntensityRemove;
        wxStaticText* StaticText13;
        wxChoice* ButtonTabEventType;
        wxStaticText* JoystickCorrectionsName;
        wxNotebook* Notebook2;
        wxSpinCtrl* IntensitySteps;
        wxPanel* PanelIntensity;
        wxMenuItem* MenuItemCopyProfile;
        wxStaticText* FFBTweaksName;
        wxMenuItem* MenuProfile7;
        wxStaticText* IntensityDeviceId;
        wxMenuItem* MenuProfile6;
        wxStatusBar* StatusBar1;
        wxStaticText* AxisTabDeviceId;
        wxGrid* GridPanelButton;
        wxMenuItem* MenuItemG27Ps3;
        wxStaticLine* StaticLine2;
        wxTextCtrl* MouseOptionsFilter;
        wxStaticLine* StaticLine11;
        wxMenuItem* MenuItemLinkControls;
        wxStaticText* StaticText6;
        wxStaticLine* StaticLine12;
        wxMenuItem* MenuItemT300rsPs4;
        wxStaticText* StaticText18;
        wxStaticText* StaticText17;
        wxStaticText* StaticText24;
        wxMenuItem* MenuController5;
        wxStaticText* StaticText15;
        wxStaticLine* StaticLine1;
        wxStaticText* ButtonTabEventId;
        wxTextCtrl* AxisTabSensitivity;
        wxSpinCtrl* FFBTweaksSpringGain;
        wxStaticLine* StaticLine8;
        wxMenuItem* MenuItemReplaceMouse;
        wxChoice* IntensityDirection;
        wxTextCtrl* JoystickCorrectionsLowValue;
        wxStaticText* AxisTabDeviceType;
        wxStaticLine* StaticLine5;
        wxCheckBox* CheckBoxSwitchBack;
        wxStaticLine* StaticLine10;
        wxMenuItem* MenuItemG29Ps4;
        wxStaticText* IntensityButtonId;
        wxStaticLine* StaticLine13;
        wxGrid* GridMouseOption;
        wxTextCtrl* MouseOptionsBuffer;
        wxStaticText* StaticText3;
        wxButton* ButtonTabAutoDetect;
        wxTextCtrl* AxisTabDeadZone;
        wxPanel* PanelOverall;
        wxMenuItem* MenuProfile3;
        wxStaticText* StaticText2;
        wxStaticText* StaticTextThresholdPanelButton;
        wxButton* IntensityAdd;
        wxButton* ButtonAutoDetect;
        wxStaticText* JoystickCorrectionsType;
        wxMenuItem* MenuItemNew;
        wxStaticText* ButtonTabDeviceId;
        wxStaticText* ProfileTriggerDeviceName;
        wxMenuItem* MenuProfile1;
        wxButton* ButtonFFBTweaksDelete;
        wxChoice* IntensityAxis;
        wxMenuItem* MenuItem360;
        wxButton* JoystickCorrectionAdd;
        wxStaticText* IntensityDeviceType;
        wxMenuItem* MenuProfile5;
        wxButton* ButtonTabModify;
        wxButton* AxisTabAutoDetect;
        wxCheckBox* FFBTweaksInvert;
        wxButton* IntensityModify;
        wxChoice* AxisTabEventType;
        wxMenuItem* MenuProfile8;
        wxStaticText* AxisTabDeviceName;
        wxStaticText* ProfileTriggerButtonId;
        wxMenuItem* MenuController6;
        wxStaticText* ProfileTriggerDeviceType;
        wxStaticText* JoystickCorrectionsAxis;
        wxStaticLine* StaticLine7;
        wxGrid* GridJoystickCorrections;
        wxMenu* MenuEdit;
        wxStaticText* FFBTweaksType;
        wxStaticText* StaticText16;
        wxMenuItem* MenuProfile2;
        wxPanel* PanelJoystickCorrections;
        wxGrid* GridPanelAxis;
        wxMenu* MenuFile;
        wxPanel* PanelAxis;
        wxStaticText* IntensityDeviceName;
        wxStaticText* MouseOptionsName;
        wxSpinCtrl* FFBTweaksConstantGain;
        wxMenuItem* MenuItemDS4;
        wxButton* IntensityAutoDetect;
        wxPanel* PanelButton;
        wxButton* JoystickCorrectionRemove;
        wxMenuItem* MenuController4;
        wxComboBox* AxisTabLabel;
        wxMenuItem* MenuItemPasteProfile;
        wxStaticText* StaticTextLabel;
        wxButton* Button5;
        wxMenuItem* MenuItemSaveAs;
        wxMenuItem* MenuItemJs;
        wxChoice* AxisTabShape;
        wxStaticText* AxisTabEventId;
        wxMenuItem* MenuController3;
        wxStaticText* StaticTextEmptyPanelAxis;
        wxStaticText* FFBTweaksAxis;
        wxStaticText* StaticTextDZPanelAxis;
        wxMenuItem* MenuItem2;
        wxStaticText* StaticText4;
        wxChoice* ButtonTabButtonId;
        wxStaticText* StaticText8;
        wxMenuItem* MenuItemXOne;
        wxSpinCtrl* IntensityDeadZone;
        wxMenuItem* MenuItemDfpPs2;
        wxStaticLine* StaticLine4;
        wxTextCtrl* JoystickCorrectionsHighCoef;
        wxPanel* PanelForceFeedback;
        wxButton* MouseOptionsRemove;
        wxGrid* GridIntensity;
        wxStaticText* JoystickCorrectionsId;
        wxMenu* MenuProfile;
        wxMenuItem* MenuItemReplaceMouseDPI;
        wxStaticLine* StaticLine6;
        wxPanel* PanelMouseOptions;
        wxStaticText* StaticText19;
        wxStaticText* MouseOptionsType;
        wxButton* Button7;
        wxChoice* IntensityShape;
        wxButton* Button3;
        wxButton* ButtonTabRemove;
        wxMenuItem* MenuItemXbox;
        wxMenuItem* MenuItemDS2;
        wxButton* ForceFeedbackAutoDetect;
        wxButton* ButtonTabAdd;
        wxStaticText* StaticTextButtonPanelButton;
        wxStaticLine* StaticLine3;
        wxChoice* AxisTabAxisId;
        wxMenu* MenuController;
        wxChoice* MouseOptionsInitMode;
        wxMenuItem* MenuAutoBindControls;
        wxTextCtrl* AxisTabAcceleration;
        wxStaticText* ButtonTabDeviceType;
        wxMenuItem* MenuItemSave;
        wxMenuItem* MenuItemDfPs2;
        wxMenuItem* MenuItemReplaceKeyboard;
        wxMenuItem* MenuItemSetMouseDPI;
        wxMenuItem* MenuProfile4;
        wxButton* MouseOptionsModify;
        wxSpinCtrl* FFBTweaksRumbleGain;
        wxStaticText* MouseOptionsButton;
        wxTextCtrl* JoystickCorrectionsHighValue;
        wxMenuItem* MenuItemDS3;
        wxTextCtrl* ButtonTabThreshold;
        wxStaticText* StaticText7;
        wxStaticText* StaticTextAxisPanelAxis;
        wxPanel* PanelTrigger;
        wxStaticText* StaticText11;
        wxStaticText* StaticTextShapePanelAxis;
        wxStaticText* MouseOptionsId;
        wxMenuItem* MenuItemGtfPs2;
        wxStaticText* StaticText12;
        wxStaticText* ButtonTabDeviceName;
        wxStaticText* FFBTweaksId;
        wxStaticLine* StaticLine9;
        wxMenuItem* MenuItemWindowEvents;
        wxMenuItem* MenuItemMultipleMiceAndKeyboards;
        wxMenuItem* MenuController2;
        wxButton* JoystickCorrectionModify;
        wxStaticText* StaticTextAccelPanelAxis;
        wxStaticLine* StaticLine14;
        wxStaticText* StaticText10;
        wxTextCtrl* JoystickCorrectionsLowCoef;
        wxStaticText* StaticText5;
        wxStaticText* StaticTextDelayPanelOverall;
        wxNotebook* Notebook1;
        wxStaticLine* StaticLine15;
        wxSpinCtrl* FFBTweaksDamperGain;
        wxStaticText* StaticTextSensPanelAxis;
        wxMenuItem* MenuController7;
        wxButton* ButtonDelete;
        wxButton* MouseOptionsAdd;
        wxMenuItem* MenuItemPasteController;
        wxStaticText* ProfileTriggerDeviceId;
        wxButton* JoystickCorrectionsAutoDetect;
        wxMenu* MenuAdvanced;
        wxComboBox* ButtonTabLabel;
        wxMenuItem* MenuController1;
        wxMenuItem* MenuItemCopyController;
        //*)

        wxLocale* locale;
        wxString decimalPoint;

        EventCatcher* evcatch;
        ConfigurationFile configFile;
        ConfigurationFile openedConfigFile;
        unsigned int currentController;
        unsigned int currentProfile;

        Profile tempProfile;
        Controller tempController;

        unsigned int grid1mod;
        unsigned int grid2mod;
        unsigned int grid3mod;
        unsigned int grid4mod;
        unsigned int gridJoystickCorrectionsMod;
        
        wxString default_directory;

        string buttonTabDeviceName;
        string axisTabDeviceName;
        string triggerTabDeviceName;
        string mouseTabDeviceName;
        string intensityTabDeviceName;
        string joystickTabDeviceName;
        string ffbTweaksTabDeviceName;

        DECLARE_EVENT_TABLE()
};

#endif // CONFIGMAIN_H
