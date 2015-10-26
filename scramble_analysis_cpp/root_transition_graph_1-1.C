// Mainframe macro generated from application: /home/velo/root/bin/root.exe
// By ROOT version 6.05/03 on 2015-10-15 11:02:36

#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGedFrame
#include "TGedFrame.h"
#endif
#ifndef ROOT_TH1Editor
#include "TH1Editor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGedPatternSelect
#include "TGedPatternSelect.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TRootBrowser
#include "TRootBrowser.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGedEditor
#include "TGedEditor.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TPadEditor
#include "TPadEditor.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCommandPlugin
#include "TGCommandPlugin.h"
#endif
#ifndef ROOT_TRootDialog
#include "TRootDialog.h"
#endif
#ifndef ROOT_TTextEditor
#include "TTextEditor.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TAttMarkerEditor
#include "TAttMarkerEditor.h"
#endif
#ifndef ROOT_TGTextEdit
#include "TGTextEdit.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TRootContextMenu
#include "TRootContextMenu.h"
#endif
#ifndef ROOT_TGDNDManager
#include "TGDNDManager.h"
#endif
#ifndef ROOT_TAxisEditor
#include "TAxisEditor.h"
#endif
#ifndef ROOT_TGSlider
#include "TGSlider.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGedMarkerSelect
#include "TGedMarkerSelect.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGView
#include "TGView.h"
#endif
#ifndef ROOT_TGFileBrowser
#include "TGFileBrowser.h"
#endif
#ifndef ROOT_TGraphEditor
#include "TGraphEditor.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGTextEditor
#include "TGTextEditor.h"
#endif
#ifndef ROOT_TRootCanvas
#include "TRootCanvas.h"
#endif
#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TAttLineEditor
#include "TAttLineEditor.h"
#endif
#ifndef ROOT_TAttTextEditor
#include "TAttTextEditor.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TAttFillEditor
#include "TAttFillEditor.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TGHtmlBrowser
#include "TGHtmlBrowser.h"
#endif
#ifndef ROOT_TFrameEditor
#include "TFrameEditor.h"
#endif

#include "Riostream.h"

void root_transition_graph_1-1()
{

   // main frame
   TGMainFrame *fRootBrowser1009 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);

   // vertical frame
   TGVerticalFrame *fVerticalFrame1010 = new TGVerticalFrame(fRootBrowser1009,1680,939,kVerticalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1011 = new TGHorizontalFrame(fVerticalFrame1010,1680,27,kHorizontalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1012 = new TGHorizontalFrame(fHorizontalFrame1011,59,27,kHorizontalFrame | kRaisedFrame);

   // menu bar
   TGMenuBar *fMenuBar1013 = new TGMenuBar(fHorizontalFrame1012,57,23,kHorizontalFrame);

   // "Browser" menu
   TGPopupMenu *fPopupMenu1015 = new TGPopupMenu(gClient->GetDefaultRoot(),165,239,kOwnBackground);
   fPopupMenu1015->AddEntry("&Browse...\tCtrl+B",11011);
   fPopupMenu1015->AddEntry("&Open...\tCtrl+O",11012);
   fPopupMenu1015->AddSeparator();

   // cascaded menu "Browser Help..."
   TGPopupMenu *fPopupMenu1016 = new TGPopupMenu(gClient->GetDefaultRoot(),181,162,kOwnBackground);
   fPopupMenu1016->AddEntry("&About ROOT...",11014);
   fPopupMenu1016->AddSeparator();
   fPopupMenu1016->AddEntry("Help On Browser...",11015);
   fPopupMenu1016->AddEntry("Help On Canvas...",11016);
   fPopupMenu1016->AddEntry("Help On Menus...",11017);
   fPopupMenu1016->AddEntry("Help On Graphics Editor...",11018);
   fPopupMenu1016->AddEntry("Help On Objects...",11019);
   fPopupMenu1016->AddEntry("Help On PostScript...",11020);
   fPopupMenu1016->AddEntry("Help On Remote Session...",11021);
   fPopupMenu1015->AddPopup("Browser Help...",fPopupMenu1016);
   fPopupMenu1015->AddSeparator();
   fPopupMenu1015->AddEntry("&Clone\tCtrl+N",11013);
   fPopupMenu1015->AddSeparator();
   fPopupMenu1015->AddEntry("New &Editor\tCtrl+E",11022);
   fPopupMenu1015->AddEntry("New &Canvas\tCtrl+C",11023);
   fPopupMenu1015->AddEntry("New &HTML\tCtrl+H",11024);
   fPopupMenu1015->AddSeparator();

   // cascaded menu "Execute Plugin..."
   TGPopupMenu *fPopupMenu1017 = new TGPopupMenu(gClient->GetDefaultRoot(),98,44,kOwnBackground);
   fPopupMenu1017->AddEntry("&Macro...",11025);
   fPopupMenu1017->AddEntry("&Command...",11026);
   fPopupMenu1015->AddPopup("Execute &Plugin...",fPopupMenu1017);
   fPopupMenu1015->AddSeparator();
   fPopupMenu1015->AddEntry("Close &Tab\tCtrl+T",11027);
   fPopupMenu1015->AddEntry("Close &Window\tCtrl+W",11028);
   fPopupMenu1015->AddSeparator();
   fPopupMenu1015->AddEntry("&Quit Root\tCtrl+Q",11029);
   fMenuBar1013->AddPopup("&Browser",fPopupMenu1015, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));
   fHorizontalFrame1012->AddFrame(fMenuBar1013, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,1,1));

   fHorizontalFrame1011->AddFrame(fHorizontalFrame1012, new TGLayoutHints(kLHintsNormal));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1019 = new TGHorizontalFrame(fHorizontalFrame1011,1621,27,kHorizontalFrame | kRaisedFrame);

   // menu bar
   TGMenuBar *fMenuBar1122 = new TGMenuBar(fHorizontalFrame1019,1619,23,kHorizontalFrame);

   // "File" menu
   TGPopupMenu *fPopupMenu1114 = new TGPopupMenu(gClient->GetDefaultRoot(),102,113,kOwnBackground);
   fPopupMenu1114->AddEntry("&New Canvas",0);
   fPopupMenu1114->AddEntry("&Open...",1);
   fPopupMenu1114->AddEntry("&Close Canvas",13);
   fPopupMenu1114->DisableEntry(13);
   fPopupMenu1114->HideEntry(13);
   fPopupMenu1114->AddSeparator();

   // cascaded menu "Save"
   TGPopupMenu *fPopupMenu1113 = new TGPopupMenu(gClient->GetDefaultRoot(),114,177,kOwnBackground);
   fPopupMenu1113->AddEntry("Canvas_1.&ps",5);
   fPopupMenu1113->AddEntry("Canvas_1.&eps",6);
   fPopupMenu1113->AddEntry("Canvas_1.p&df",7);
   fPopupMenu1113->AddEntry("Canvas_1.&tex",11);
   fPopupMenu1113->AddEntry("Canvas_1.&gif",8);
   fPopupMenu1113->AddEntry("Canvas_1.&jpg",9);
   fPopupMenu1113->AddEntry("Canvas_1.&png",10);
   fPopupMenu1113->AddEntry("Canvas_1.&C",4);
   fPopupMenu1113->AddEntry("Canvas_1.&root",3);
   fPopupMenu1114->AddPopup("&Save",fPopupMenu1113);
   fPopupMenu1114->AddEntry("Save &As...",2);
   fPopupMenu1114->AddSeparator();
   fPopupMenu1114->AddEntry("&Print...",12);
   fPopupMenu1114->AddSeparator();
   fPopupMenu1114->AddEntry("&Quit ROOT",14);
   fPopupMenu1114->DisableEntry(14);
   fPopupMenu1114->HideEntry(14);
   fMenuBar1122->AddPopup("&File",fPopupMenu1114, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Edit" menu
   TGPopupMenu *fPopupMenu1116 = new TGPopupMenu(gClient->GetDefaultRoot(),69,151,kOwnBackground);
   fPopupMenu1116->AddEntry("&Style...",15);
   fPopupMenu1116->AddSeparator();
   fPopupMenu1116->AddEntry("Cu&t",16);
   fPopupMenu1116->DisableEntry(16);
   fPopupMenu1116->AddEntry("&Copy",17);
   fPopupMenu1116->DisableEntry(17);
   fPopupMenu1116->AddEntry("&Paste",18);
   fPopupMenu1116->DisableEntry(18);
   fPopupMenu1116->AddSeparator();

   // cascaded menu "Clear"
   TGPopupMenu *fPopupMenu1115 = new TGPopupMenu(gClient->GetDefaultRoot(),74,44,kOwnBackground);
   fPopupMenu1115->AddEntry("&Pad",19);
   fPopupMenu1115->AddEntry("&Canvas",20);
   fPopupMenu1116->AddPopup("C&lear",fPopupMenu1115);
   fPopupMenu1116->AddSeparator();
   fPopupMenu1116->AddEntry("&Undo",21);
   fPopupMenu1116->DisableEntry(21);
   fPopupMenu1116->AddEntry("&Redo",22);
   fPopupMenu1116->DisableEntry(22);
   fMenuBar1122->AddPopup("&Edit",fPopupMenu1116, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "View" menu
   TGPopupMenu *fPopupMenu1118 = new TGPopupMenu(gClient->GetDefaultRoot(),122,189,kOwnBackground);
   fPopupMenu1118->AddEntry("&Editor",23);
   fPopupMenu1118->AddEntry("&Toolbar",24);
   fPopupMenu1118->AddEntry("Event &Statusbar",25);
   fPopupMenu1118->AddEntry("T&oolTip Info",26);
   fPopupMenu1118->AddSeparator();
   fPopupMenu1118->AddEntry("&Colors",27);
   fPopupMenu1118->AddEntry("&Fonts",28);
   fPopupMenu1118->DisableEntry(28);
   fPopupMenu1118->AddEntry("&Markers",29);
   fPopupMenu1118->AddSeparator();
   fPopupMenu1118->AddEntry("&Iconify",30);
   fPopupMenu1118->AddSeparator();

   // cascaded menu "View With"
   TGPopupMenu *fPopupMenu1117 = new TGPopupMenu(gClient->GetDefaultRoot(),76,44,kOwnBackground);
   fPopupMenu1117->AddEntry("&X3D",31);
   fPopupMenu1117->AddEntry("&OpenGL",32);
   fPopupMenu1118->AddPopup("&View With",fPopupMenu1117);
   fMenuBar1122->AddPopup("&View",fPopupMenu1118, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Options" menu
   TGPopupMenu *fPopupMenu1119 = new TGPopupMenu(gClient->GetDefaultRoot(),148,227,kOwnBackground);
   fPopupMenu1119->AddEntry("&Auto Resize Canvas",33);
   fPopupMenu1119->CheckEntry(33);
   fPopupMenu1119->AddEntry("&Resize Canvas",34);
   fPopupMenu1119->AddEntry("&Move Opaque",35);
   fPopupMenu1119->CheckEntry(35);
   fPopupMenu1119->AddEntry("Resize &Opaque",36);
   fPopupMenu1119->CheckEntry(36);
   fPopupMenu1119->AddSeparator();
   fPopupMenu1119->AddEntry("&Interrupt",37);
   fPopupMenu1119->AddEntry("R&efresh",38);
   fPopupMenu1119->AddSeparator();
   fPopupMenu1119->AddEntry("&Pad Auto Exec",39);
   fPopupMenu1119->AddSeparator();
   fPopupMenu1119->AddEntry("&Statistics",40);
   fPopupMenu1119->CheckEntry(40);
   fPopupMenu1119->AddEntry("Histogram &Title",41);
   fPopupMenu1119->CheckEntry(41);
   fPopupMenu1119->AddEntry("&Fit Parameters",42);
   fPopupMenu1119->AddEntry("Can Edit &Histograms",43);
   fMenuBar1122->AddPopup("&Options",fPopupMenu1119, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Tools" menu
   TGPopupMenu *fPopupMenu1120 = new TGPopupMenu(gClient->GetDefaultRoot(),120,120,kOwnBackground);
   fPopupMenu1120->AddEntry("&Inspect ROOT",44);
   fPopupMenu1120->AddEntry("&Class Tree",45);
   fPopupMenu1120->AddEntry("&Fit Panel",46);
   fPopupMenu1120->AddEntry("&Start Browser",47);
   fPopupMenu1120->AddEntry("&Gui Builder",48);
   fPopupMenu1120->AddEntry("&Event Recorder",49);
   fMenuBar1122->AddPopup("&Tools",fPopupMenu1120, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Help" menu
   TGPopupMenu *fPopupMenu1121 = new TGPopupMenu(gClient->GetDefaultRoot(),120,166,kOwnBackground);
   fPopupMenu1121->AddLabel("Basic Help On...");
   fPopupMenu1121->DefaultEntry(-1);
   fPopupMenu1121->AddSeparator();
   fPopupMenu1121->AddEntry("&Canvas",51);
   fPopupMenu1121->AddEntry("&Menus",52);
   fPopupMenu1121->AddEntry("&Graphics Editor",53);
   fPopupMenu1121->AddEntry("&Browser",54);
   fPopupMenu1121->AddEntry("&Objects",55);
   fPopupMenu1121->AddEntry("&PostScript",56);
   fPopupMenu1121->AddSeparator();
   fPopupMenu1121->AddEntry("&About ROOT...",50);
   fMenuBar1122->AddPopup("&Help",fPopupMenu1121, new TGLayoutHints(kLHintsRight | kLHintsTop));
   fHorizontalFrame1019->AddFrame(fMenuBar1122, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,1,1));

   // menu bar
   TGMenuBar *fMenuBar1167 = new TGMenuBar(fHorizontalFrame1019,739,23,kHorizontalFrame);

   // "File" menu
   TGPopupMenu *fPopupMenu1162 = new TGPopupMenu(gClient->GetDefaultRoot(),87,132,kOwnBackground);
   fPopupMenu1162->AddEntry("&New",0);
   fPopupMenu1162->AddSeparator();
   fPopupMenu1162->AddEntry("&Open...",1);
   fPopupMenu1162->AddEntry("&Close",4);
   fPopupMenu1162->AddEntry("&Save",2);
   fPopupMenu1162->AddEntry("Save &As...",3);
   fPopupMenu1162->AddSeparator();
   fPopupMenu1162->AddEntry("&Print...",5);
   fPopupMenu1162->AddSeparator();
   fPopupMenu1162->AddEntry("E&xit",6);
   fPopupMenu1162->DisableEntry(6);
   fPopupMenu1162->HideEntry(6);
   fMenuBar1167->AddPopup("&File",fPopupMenu1162, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Edit" menu
   TGPopupMenu *fPopupMenu1163 = new TGPopupMenu(gClient->GetDefaultRoot(),137,128,kOwnBackground);
   fPopupMenu1163->AddEntry("Cu&t\tCtrl+X",7);
   fPopupMenu1163->DisableEntry(7);
   fPopupMenu1163->AddEntry("&Copy\tCtrl+C",8);
   fPopupMenu1163->DisableEntry(8);
   fPopupMenu1163->AddEntry("&Paste\tCtrl+V",9);
   fPopupMenu1163->DisableEntry(9);
   fPopupMenu1163->AddEntry("De&lete\tDel",10);
   fPopupMenu1163->DisableEntry(10);
   fPopupMenu1163->AddSeparator();
   fPopupMenu1163->AddEntry("Select &All\tCtrl+A",11);
   fPopupMenu1163->AddSeparator();
   fPopupMenu1163->AddEntry("Set &Font",20);
   fMenuBar1167->AddPopup("&Edit",fPopupMenu1163, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Search" menu
   TGPopupMenu *fPopupMenu1165 = new TGPopupMenu(gClient->GetDefaultRoot(),144,67,kOwnBackground);
   fPopupMenu1165->AddEntry("&Find...\tCtrl+F",12);
   fPopupMenu1165->AddEntry("Find &Next\tF3",13);
   fPopupMenu1165->AddSeparator();
   fPopupMenu1165->AddEntry("&Goto Line...\tCtrl+L",14);
   fMenuBar1167->AddPopup("&Search",fPopupMenu1165, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Tools" menu
   TGPopupMenu *fPopupMenu1164 = new TGPopupMenu(gClient->GetDefaultRoot(),174,63,kOwnBackground);
   fPopupMenu1164->AddEntry("&Compile Macro\tCtrl+F7",15);
   fPopupMenu1164->AddEntry("&Execute Macro\tCtrl+F5",16);
   fPopupMenu1164->AddEntry("&Interrupt\tShift+F5",17);
   fMenuBar1167->AddPopup("&Tools",fPopupMenu1164, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Help" menu
   TGPopupMenu *fPopupMenu1166 = new TGPopupMenu(gClient->GetDefaultRoot(),127,48,kOwnBackground);
   fPopupMenu1166->AddEntry("&Help Topics\tF1",18);
   fPopupMenu1166->AddSeparator();
   fPopupMenu1166->AddEntry("&About...",19);
   fMenuBar1167->AddPopup("&Help",fPopupMenu1166, new TGLayoutHints(kLHintsRight | kLHintsTop));
   fHorizontalFrame1019->AddFrame(fMenuBar1167, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,1,1));

   // menu bar
   TGMenuBar *fMenuBar1327 = new TGMenuBar(fHorizontalFrame1019,1619,23,kHorizontalFrame);

   // "File" menu
   TGPopupMenu *fPopupMenu1319 = new TGPopupMenu(gClient->GetDefaultRoot(),102,113,kOwnBackground);
   fPopupMenu1319->AddEntry("&New Canvas",0);
   fPopupMenu1319->AddEntry("&Open...",1);
   fPopupMenu1319->AddEntry("&Close Canvas",13);
   fPopupMenu1319->DisableEntry(13);
   fPopupMenu1319->HideEntry(13);
   fPopupMenu1319->AddSeparator();

   // cascaded menu "Save"
   TGPopupMenu *fPopupMenu1318 = new TGPopupMenu(gClient->GetDefaultRoot(),135,177,kOwnBackground);
   fPopupMenu1318->AddEntry("Canvas_1_n2.&ps",5);
   fPopupMenu1318->AddEntry("Canvas_1_n2.&eps",6);
   fPopupMenu1318->AddEntry("Canvas_1_n2.p&df",7);
   fPopupMenu1318->AddEntry("Canvas_1_n2.&tex",11);
   fPopupMenu1318->AddEntry("Canvas_1_n2.&gif",8);
   fPopupMenu1318->AddEntry("Canvas_1_n2.&jpg",9);
   fPopupMenu1318->AddEntry("Canvas_1_n2.&png",10);
   fPopupMenu1318->AddEntry("Canvas_1_n2.&C",4);
   fPopupMenu1318->AddEntry("Canvas_1_n2.&root",3);
   fPopupMenu1319->AddPopup("&Save",fPopupMenu1318);
   fPopupMenu1319->AddEntry("Save &As...",2);
   fPopupMenu1319->AddSeparator();
   fPopupMenu1319->AddEntry("&Print...",12);
   fPopupMenu1319->AddSeparator();
   fPopupMenu1319->AddEntry("&Quit ROOT",14);
   fPopupMenu1319->DisableEntry(14);
   fPopupMenu1319->HideEntry(14);
   fMenuBar1327->AddPopup("&File",fPopupMenu1319, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Edit" menu
   TGPopupMenu *fPopupMenu1321 = new TGPopupMenu(gClient->GetDefaultRoot(),69,151,kOwnBackground);
   fPopupMenu1321->AddEntry("&Style...",15);
   fPopupMenu1321->AddSeparator();
   fPopupMenu1321->AddEntry("Cu&t",16);
   fPopupMenu1321->DisableEntry(16);
   fPopupMenu1321->AddEntry("&Copy",17);
   fPopupMenu1321->DisableEntry(17);
   fPopupMenu1321->AddEntry("&Paste",18);
   fPopupMenu1321->DisableEntry(18);
   fPopupMenu1321->AddSeparator();

   // cascaded menu "Clear"
   TGPopupMenu *fPopupMenu1320 = new TGPopupMenu(gClient->GetDefaultRoot(),74,44,kOwnBackground);
   fPopupMenu1320->AddEntry("&Pad",19);
   fPopupMenu1320->AddEntry("&Canvas",20);
   fPopupMenu1321->AddPopup("C&lear",fPopupMenu1320);
   fPopupMenu1321->AddSeparator();
   fPopupMenu1321->AddEntry("&Undo",21);
   fPopupMenu1321->DisableEntry(21);
   fPopupMenu1321->AddEntry("&Redo",22);
   fPopupMenu1321->DisableEntry(22);
   fMenuBar1327->AddPopup("&Edit",fPopupMenu1321, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "View" menu
   TGPopupMenu *fPopupMenu1323 = new TGPopupMenu(gClient->GetDefaultRoot(),122,189,kOwnBackground);
   fPopupMenu1323->AddEntry("&Editor",23);
   fPopupMenu1323->AddEntry("&Toolbar",24);
   fPopupMenu1323->AddEntry("Event &Statusbar",25);
   fPopupMenu1323->AddEntry("T&oolTip Info",26);
   fPopupMenu1323->AddSeparator();
   fPopupMenu1323->AddEntry("&Colors",27);
   fPopupMenu1323->AddEntry("&Fonts",28);
   fPopupMenu1323->DisableEntry(28);
   fPopupMenu1323->AddEntry("&Markers",29);
   fPopupMenu1323->AddSeparator();
   fPopupMenu1323->AddEntry("&Iconify",30);
   fPopupMenu1323->AddSeparator();

   // cascaded menu "View With"
   TGPopupMenu *fPopupMenu1322 = new TGPopupMenu(gClient->GetDefaultRoot(),76,44,kOwnBackground);
   fPopupMenu1322->AddEntry("&X3D",31);
   fPopupMenu1322->AddEntry("&OpenGL",32);
   fPopupMenu1323->AddPopup("&View With",fPopupMenu1322);
   fMenuBar1327->AddPopup("&View",fPopupMenu1323, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Options" menu
   TGPopupMenu *fPopupMenu1324 = new TGPopupMenu(gClient->GetDefaultRoot(),148,227,kOwnBackground);
   fPopupMenu1324->AddEntry("&Auto Resize Canvas",33);
   fPopupMenu1324->CheckEntry(33);
   fPopupMenu1324->AddEntry("&Resize Canvas",34);
   fPopupMenu1324->AddEntry("&Move Opaque",35);
   fPopupMenu1324->CheckEntry(35);
   fPopupMenu1324->AddEntry("Resize &Opaque",36);
   fPopupMenu1324->CheckEntry(36);
   fPopupMenu1324->AddSeparator();
   fPopupMenu1324->AddEntry("&Interrupt",37);
   fPopupMenu1324->AddEntry("R&efresh",38);
   fPopupMenu1324->AddSeparator();
   fPopupMenu1324->AddEntry("&Pad Auto Exec",39);
   fPopupMenu1324->AddSeparator();
   fPopupMenu1324->AddEntry("&Statistics",40);
   fPopupMenu1324->CheckEntry(40);
   fPopupMenu1324->AddEntry("Histogram &Title",41);
   fPopupMenu1324->CheckEntry(41);
   fPopupMenu1324->AddEntry("&Fit Parameters",42);
   fPopupMenu1324->AddEntry("Can Edit &Histograms",43);
   fMenuBar1327->AddPopup("&Options",fPopupMenu1324, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Tools" menu
   TGPopupMenu *fPopupMenu1325 = new TGPopupMenu(gClient->GetDefaultRoot(),120,120,kOwnBackground);
   fPopupMenu1325->AddEntry("&Inspect ROOT",44);
   fPopupMenu1325->AddEntry("&Class Tree",45);
   fPopupMenu1325->AddEntry("&Fit Panel",46);
   fPopupMenu1325->AddEntry("&Start Browser",47);
   fPopupMenu1325->AddEntry("&Gui Builder",48);
   fPopupMenu1325->AddEntry("&Event Recorder",49);
   fMenuBar1327->AddPopup("&Tools",fPopupMenu1325, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Help" menu
   TGPopupMenu *fPopupMenu1326 = new TGPopupMenu(gClient->GetDefaultRoot(),120,166,kOwnBackground);
   fPopupMenu1326->AddLabel("Basic Help On...");
   fPopupMenu1326->DefaultEntry(-1);
   fPopupMenu1326->AddSeparator();
   fPopupMenu1326->AddEntry("&Canvas",51);
   fPopupMenu1326->AddEntry("&Menus",52);
   fPopupMenu1326->AddEntry("&Graphics Editor",53);
   fPopupMenu1326->AddEntry("&Browser",54);
   fPopupMenu1326->AddEntry("&Objects",55);
   fPopupMenu1326->AddEntry("&PostScript",56);
   fPopupMenu1326->AddSeparator();
   fPopupMenu1326->AddEntry("&About ROOT...",50);
   fMenuBar1327->AddPopup("&Help",fPopupMenu1326, new TGLayoutHints(kLHintsRight | kLHintsTop));
   fHorizontalFrame1019->AddFrame(fMenuBar1327, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,1,1));

   // menu bar
   TGMenuBar *fMenuBar1416 = new TGMenuBar(fHorizontalFrame1019,1619,23,kHorizontalFrame);

   // "File" menu
   TGPopupMenu *fPopupMenu1408 = new TGPopupMenu(gClient->GetDefaultRoot(),102,113,kOwnBackground);
   fPopupMenu1408->AddEntry("&New Canvas",0);
   fPopupMenu1408->AddEntry("&Open...",1);
   fPopupMenu1408->AddEntry("&Close Canvas",13);
   fPopupMenu1408->DisableEntry(13);
   fPopupMenu1408->HideEntry(13);
   fPopupMenu1408->AddSeparator();

   // cascaded menu "Save"
   TGPopupMenu *fPopupMenu1407 = new TGPopupMenu(gClient->GetDefaultRoot(),135,177,kOwnBackground);
   fPopupMenu1407->AddEntry("Canvas_1_n3.&ps",5);
   fPopupMenu1407->AddEntry("Canvas_1_n3.&eps",6);
   fPopupMenu1407->AddEntry("Canvas_1_n3.p&df",7);
   fPopupMenu1407->AddEntry("Canvas_1_n3.&tex",11);
   fPopupMenu1407->AddEntry("Canvas_1_n3.&gif",8);
   fPopupMenu1407->AddEntry("Canvas_1_n3.&jpg",9);
   fPopupMenu1407->AddEntry("Canvas_1_n3.&png",10);
   fPopupMenu1407->AddEntry("Canvas_1_n3.&C",4);
   fPopupMenu1407->AddEntry("Canvas_1_n3.&root",3);
   fPopupMenu1408->AddPopup("&Save",fPopupMenu1407);
   fPopupMenu1408->AddEntry("Save &As...",2);
   fPopupMenu1408->AddSeparator();
   fPopupMenu1408->AddEntry("&Print...",12);
   fPopupMenu1408->AddSeparator();
   fPopupMenu1408->AddEntry("&Quit ROOT",14);
   fPopupMenu1408->DisableEntry(14);
   fPopupMenu1408->HideEntry(14);
   fMenuBar1416->AddPopup("&File",fPopupMenu1408, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Edit" menu
   TGPopupMenu *fPopupMenu1410 = new TGPopupMenu(gClient->GetDefaultRoot(),69,151,kOwnBackground);
   fPopupMenu1410->AddEntry("&Style...",15);
   fPopupMenu1410->AddSeparator();
   fPopupMenu1410->AddEntry("Cu&t",16);
   fPopupMenu1410->DisableEntry(16);
   fPopupMenu1410->AddEntry("&Copy",17);
   fPopupMenu1410->DisableEntry(17);
   fPopupMenu1410->AddEntry("&Paste",18);
   fPopupMenu1410->DisableEntry(18);
   fPopupMenu1410->AddSeparator();

   // cascaded menu "Clear"
   TGPopupMenu *fPopupMenu1409 = new TGPopupMenu(gClient->GetDefaultRoot(),74,44,kOwnBackground);
   fPopupMenu1409->AddEntry("&Pad",19);
   fPopupMenu1409->AddEntry("&Canvas",20);
   fPopupMenu1410->AddPopup("C&lear",fPopupMenu1409);
   fPopupMenu1410->AddSeparator();
   fPopupMenu1410->AddEntry("&Undo",21);
   fPopupMenu1410->DisableEntry(21);
   fPopupMenu1410->AddEntry("&Redo",22);
   fPopupMenu1410->DisableEntry(22);
   fMenuBar1416->AddPopup("&Edit",fPopupMenu1410, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "View" menu
   TGPopupMenu *fPopupMenu1412 = new TGPopupMenu(gClient->GetDefaultRoot(),122,189,kOwnBackground);
   fPopupMenu1412->AddEntry("&Editor",23);
   fPopupMenu1412->AddEntry("&Toolbar",24);
   fPopupMenu1412->AddEntry("Event &Statusbar",25);
   fPopupMenu1412->AddEntry("T&oolTip Info",26);
   fPopupMenu1412->AddSeparator();
   fPopupMenu1412->AddEntry("&Colors",27);
   fPopupMenu1412->AddEntry("&Fonts",28);
   fPopupMenu1412->DisableEntry(28);
   fPopupMenu1412->AddEntry("&Markers",29);
   fPopupMenu1412->AddSeparator();
   fPopupMenu1412->AddEntry("&Iconify",30);
   fPopupMenu1412->AddSeparator();

   // cascaded menu "View With"
   TGPopupMenu *fPopupMenu1411 = new TGPopupMenu(gClient->GetDefaultRoot(),76,44,kOwnBackground);
   fPopupMenu1411->AddEntry("&X3D",31);
   fPopupMenu1411->AddEntry("&OpenGL",32);
   fPopupMenu1412->AddPopup("&View With",fPopupMenu1411);
   fMenuBar1416->AddPopup("&View",fPopupMenu1412, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Options" menu
   TGPopupMenu *fPopupMenu1413 = new TGPopupMenu(gClient->GetDefaultRoot(),148,227,kOwnBackground);
   fPopupMenu1413->AddEntry("&Auto Resize Canvas",33);
   fPopupMenu1413->CheckEntry(33);
   fPopupMenu1413->AddEntry("&Resize Canvas",34);
   fPopupMenu1413->AddEntry("&Move Opaque",35);
   fPopupMenu1413->CheckEntry(35);
   fPopupMenu1413->AddEntry("Resize &Opaque",36);
   fPopupMenu1413->CheckEntry(36);
   fPopupMenu1413->AddSeparator();
   fPopupMenu1413->AddEntry("&Interrupt",37);
   fPopupMenu1413->AddEntry("R&efresh",38);
   fPopupMenu1413->AddSeparator();
   fPopupMenu1413->AddEntry("&Pad Auto Exec",39);
   fPopupMenu1413->AddSeparator();
   fPopupMenu1413->AddEntry("&Statistics",40);
   fPopupMenu1413->CheckEntry(40);
   fPopupMenu1413->AddEntry("Histogram &Title",41);
   fPopupMenu1413->CheckEntry(41);
   fPopupMenu1413->AddEntry("&Fit Parameters",42);
   fPopupMenu1413->AddEntry("Can Edit &Histograms",43);
   fMenuBar1416->AddPopup("&Options",fPopupMenu1413, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Tools" menu
   TGPopupMenu *fPopupMenu1414 = new TGPopupMenu(gClient->GetDefaultRoot(),120,120,kOwnBackground);
   fPopupMenu1414->AddEntry("&Inspect ROOT",44);
   fPopupMenu1414->AddEntry("&Class Tree",45);
   fPopupMenu1414->AddEntry("&Fit Panel",46);
   fPopupMenu1414->AddEntry("&Start Browser",47);
   fPopupMenu1414->AddEntry("&Gui Builder",48);
   fPopupMenu1414->AddEntry("&Event Recorder",49);
   fMenuBar1416->AddPopup("&Tools",fPopupMenu1414, new TGLayoutHints(kLHintsLeft | kLHintsTop,0,4,0,0));

   // "Help" menu
   TGPopupMenu *fPopupMenu1415 = new TGPopupMenu(gClient->GetDefaultRoot(),120,166,kOwnBackground);
   fPopupMenu1415->AddLabel("Basic Help On...");
   fPopupMenu1415->DefaultEntry(-1);
   fPopupMenu1415->AddSeparator();
   fPopupMenu1415->AddEntry("&Canvas",51);
   fPopupMenu1415->AddEntry("&Menus",52);
   fPopupMenu1415->AddEntry("&Graphics Editor",53);
   fPopupMenu1415->AddEntry("&Browser",54);
   fPopupMenu1415->AddEntry("&Objects",55);
   fPopupMenu1415->AddEntry("&PostScript",56);
   fPopupMenu1415->AddSeparator();
   fPopupMenu1415->AddEntry("&About ROOT...",50);
   fMenuBar1416->AddPopup("&Help",fPopupMenu1415, new TGLayoutHints(kLHintsRight | kLHintsTop));
   fHorizontalFrame1019->AddFrame(fMenuBar1416, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,1,1));

   fHorizontalFrame1011->AddFrame(fHorizontalFrame1019, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   fVerticalFrame1010->AddFrame(fHorizontalFrame1011, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1020 = new TGHorizontalFrame(fVerticalFrame1010,400,2,kHorizontalFrame | kRaisedFrame);

   fVerticalFrame1010->AddFrame(fHorizontalFrame1020, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1021 = new TGHorizontalFrame(fVerticalFrame1010,1680,912,kHorizontalFrame);

   // vertical frame
   TGVerticalFrame *fVerticalFrame1022 = new TGVerticalFrame(fHorizontalFrame1021,250,912,kVerticalFrame | kFixedWidth);

   // tab widget
   TGTab *fTab1026 = new TGTab(fVerticalFrame1022,246,908);

   // container of "Files"
   TGCompositeFrame *fCompositeFrame1041;
   fCompositeFrame1041 = fTab1026->AddTab("Files");
   fCompositeFrame1041->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1041));

   // composite frame
   TGCompositeFrame *fFileBrowser1042 = new TGCompositeFrame(fCompositeFrame1041,242,882,kVerticalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1043 = new TGHorizontalFrame(fFileBrowser1042,238,24,kHorizontalFrame);

   ULong_t ucolor;        // will reflect user color changes
   gClient->GetColorByName("#ffffff",ucolor);

   // combo box
   TGComboBox *fComboBox1044 = new TGComboBox(fHorizontalFrame1043,"same",-1,kHorizontalFrame | kSunkenFrame | kOwnBackground);
   fComboBox1044->AddEntry("",1);
   fComboBox1044->AddEntry("box",2);
   fComboBox1044->AddEntry("colz",3);
   fComboBox1044->AddEntry("lego",4);
   fComboBox1044->AddEntry("lego1",5);
   fComboBox1044->AddEntry("lego2",6);
   fComboBox1044->AddEntry("same",7);
   fComboBox1044->AddEntry("surf",8);
   fComboBox1044->AddEntry("surf1",9);
   fComboBox1044->AddEntry("surf2",10);
   fComboBox1044->AddEntry("surf3",11);
   fComboBox1044->AddEntry("surf4",12);
   fComboBox1044->AddEntry("surf5",13);
   fComboBox1044->AddEntry("text",14);
   fComboBox1044->Resize(80,20);
   fComboBox1044->Select(7);
   fHorizontalFrame1043->AddFrame(fComboBox1044, new TGLayoutHints(kLHintsRight | kLHintsCenterY,2,2,2,2));
   TGLabel *fLabel1071 = new TGLabel(fHorizontalFrame1043,"Draw Option:");
   fLabel1071->SetTextJustify(36);
   fLabel1071->SetMargins(0,0,0,0);
   fLabel1071->SetWrapLength(-1);
   fHorizontalFrame1043->AddFrame(fLabel1071, new TGLayoutHints(kLHintsRight | kLHintsCenterY,5,2,2,2));
   TGPictureButton *fPictureButton1072 = new TGPictureButton(fHorizontalFrame1043,gClient->GetPicture("bld_sortup.png"),-1,TGPictureButton::GetDefaultGC()(),kChildFrame);
   fPictureButton1072->SetToolTipText("Sort Alphabetically\n(Current folder only)");
   fHorizontalFrame1043->AddFrame(fPictureButton1072, new TGLayoutHints(kLHintsLeft | kLHintsCenterY,2,2,2,2));
   fPictureButton1072->Connect("Clicked()", 0, 0, "ToggleSort()");
   TGPictureButton *fPictureButton1075 = new TGPictureButton(fHorizontalFrame1043,gClient->GetPicture("filter.png"),-1,TGPictureButton::GetDefaultGC()(),kChildFrame);
   fPictureButton1075->SetToolTipText("Filter Content");
   fHorizontalFrame1043->AddFrame(fPictureButton1075, new TGLayoutHints(kLHintsLeft | kLHintsCenterY,2,2,2,2));
   fPictureButton1075->Connect("Clicked()", 0, 0, "RequestFilter()");
   TGPictureButton *fPictureButton1078 = new TGPictureButton(fHorizontalFrame1043,gClient->GetPicture("refresh.png"),-1,TGPictureButton::GetDefaultGC()(),kChildFrame);
   fPictureButton1078->SetToolTipText("Refresh Current Folder");
   fHorizontalFrame1043->AddFrame(fPictureButton1078, new TGLayoutHints(kLHintsLeft | kLHintsCenterY,2,5,2,2));
   fPictureButton1078->Connect("Clicked()", 0, 0, "Refresh()");

   fFileBrowser1042->AddFrame(fHorizontalFrame1043, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));

   // canvas widget
   TGCanvas *fCanvas1081 = new TGCanvas(fFileBrowser1042,242,826,kSunkenFrame);

   // canvas viewport
   TGViewPort *fViewPort1082 = fCanvas1081->GetViewPort();

   // list tree
   TGListTree *fListTree1091 = new TGListTree(fCanvas1081,kHorizontalFrame);

   const TGPicture *popen;       //used for list tree items
   const TGPicture *pclose;      //used for list tree items

   TGListTreeItem *item80 = fListTree1091->AddItem(NULL,"root");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item80->SetPictures(popen, pclose);
   item80->SetTipText("root\nroot of all folders");
   fListTree1091->CloseItem(item80);
   TGListTreeItem *item81 = fListTree1091->AddItem(NULL,"PROOF Sessions");
   item81->SetPictures(popen, pclose);
   item81->SetTipText("Proofs\nDoubly linked list");
   fListTree1091->CloseItem(item81);
   TGListTreeItem *item82 = fListTree1091->AddItem(NULL,"ROOT Files");
   item82->SetPictures(popen, pclose);
   item82->SetTipText("Files\nDoubly linked list");
   fListTree1091->OpenItem(item82);
   TGListTreeItem *item83 = fListTree1091->AddItem(item82,"root_longest_chain.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item83->SetPictures(popen, pclose);
   item83->SetTipText("root_longest_chain.root\n");
   TGListTreeItem *item84 = fListTree1091->AddItem(item82,"root_transition_analysis.root");
   item84->SetPictures(popen, pclose);
   item84->SetTipText("root_transition_analysis.root\n");
   TGListTreeItem *item85 = fListTree1091->AddItem(NULL,"/");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item85->SetPictures(popen, pclose);
   fListTree1091->OpenItem(item85);
   TGListTreeItem *item86 = fListTree1091->AddItem(item85,"home");
   item86->SetPictures(popen, pclose);
   TGListTreeItem *item87 = fListTree1091->AddItem(item86,"velo");
   item87->SetPictures(popen, pclose);
   TGListTreeItem *item88 = fListTree1091->AddItem(item87,"Desktop");
   item88->SetPictures(popen, pclose);
   TGListTreeItem *item89 = fListTree1091->AddItem(item87,"Documents");
   item89->SetPictures(popen, pclose);
   TGListTreeItem *item90 = fListTree1091->AddItem(item89,"B_N_T");
   item90->SetPictures(popen, pclose);
   TGListTreeItem *item91 = fListTree1091->AddItem(item90,"new_scrambler");
   item91->SetPictures(popen, pclose);
   TGListTreeItem *item92 = fListTree1091->AddItem(item90,"new_scrambler_resource_analysis");
   item92->SetPictures(popen, pclose);
   TGListTreeItem *item93 = fListTree1091->AddItem(item90,"new_scrambler_resource_analysis_backup");
   item93->SetPictures(popen, pclose);
   TGListTreeItem *item94 = fListTree1091->AddItem(item90,"new_scrambler_transitions_vhdl");
   item94->SetPictures(popen, pclose);
   TGListTreeItem *item95 = fListTree1091->AddItem(item90,"old_scrambler_resource_analysis");
   item95->SetPictures(popen, pclose);
   TGListTreeItem *item96 = fListTree1091->AddItem(item90,"old_scrambler_transitions_vhdl");
   item96->SetPictures(popen, pclose);
   TGListTreeItem *item97 = fListTree1091->AddItem(item90,"resources");
   item97->SetPictures(popen, pclose);
   TGListTreeItem *item98 = fListTree1091->AddItem(item90,"scramble_analysis_cpp");
   item98->SetPictures(popen, pclose);
   TGListTreeItem *item99 = fListTree1091->AddItem(item98,"#root_transition_analysis.h#");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item99->SetPictures(popen, pclose);
   item99->SetTipText("#root_transition_analysis.h#\nSize: 1.5K\n2015-10-14 15:20");
   TGListTreeItem *item100 = fListTree1091->AddItem(item98,"Longest_Chain_Hist.pdf");
   popen = gClient->GetPicture("pdf.xpm__16x16");
   pclose = gClient->GetPicture("pdf.xpm__16x16");
   item100->SetPictures(popen, pclose);
   item100->SetTipText("Longest_Chain_Hist.pdf\nSize: 14.0K\n2015-10-14 16:50");
   TGListTreeItem *item101 = fListTree1091->AddItem(item98,"Makefile");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item101->SetPictures(popen, pclose);
   item101->SetTipText("Makefile\nSize: 956\n2015-10-14 15:41");
   TGListTreeItem *item102 = fListTree1091->AddItem(item98,"Makefile~");
   item102->SetPictures(popen, pclose);
   item102->SetTipText("Makefile~\nSize: 662\n2015-10-14 13:12");
   TGListTreeItem *item103 = fListTree1091->AddItem(item98,"analysis_output.txt");
   item103->SetPictures(popen, pclose);
   TGListTreeItem *item104 = fListTree1091->AddItem(item98,"desyncFilter.txt");
   item104->SetPictures(popen, pclose);
   item104->SetTipText("desyncFilter.txt\nSize: 1.6M\n2015-10-14 11:24");
   TGListTreeItem *item105 = fListTree1091->AddItem(item98,"draw_transition_graph.C");
   popen = gClient->GetPicture("macro_t.xpm__16x16");
   pclose = gClient->GetPicture("macro_t.xpm__16x16");
   item105->SetPictures(popen, pclose);
   item105->SetTipText("draw_transition_graph.C\nSize: 537\n2015-10-14 14:08");
   TGListTreeItem *item106 = fListTree1091->AddItem(item98,"draw_transition_graph.C~");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item106->SetPictures(popen, pclose);
   item106->SetTipText("draw_transition_graph.C~\nSize: 542\n2015-10-14 14:03");
   TGListTreeItem *item107 = fListTree1091->AddItem(item98,"in_check_file.txt");
   item107->SetPictures(popen, pclose);
   item107->SetTipText("in_check_file.txt\nSize: 1.6M\n2015-10-15 10:09");
   TGListTreeItem *item108 = fListTree1091->AddItem(item98,"new_scramble_output.txt");
   item108->SetPictures(popen, pclose);
   item108->SetTipText("new_scramble_output.txt\nSize: 1.6M\n2015-10-15 10:09");
   TGListTreeItem *item109 = fListTree1091->AddItem(item98,"old");
   item109->SetPictures(popen, pclose);
   item109->SetTipText("old\nSize: 13.0M\n2015-10-14 13:41");
   TGListTreeItem *item110 = fListTree1091->AddItem(item98,"old_scramble_output.txt");
   item110->SetPictures(popen, pclose);
   item110->SetTipText("old_scramble_output.txt\nSize: 1.6M\n2015-10-15 10:09");
   TGListTreeItem *item111 = fListTree1091->AddItem(item98,"root_longest_chain");
   item111->SetPictures(popen, pclose);
   item111->SetTipText("root_longest_chain\nSize: 25.1K\n2015-10-14 16:37");
   TGListTreeItem *item112 = fListTree1091->AddItem(item98,"root_longest_chain.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item112->SetPictures(popen, pclose);
   item112->SetTipText("root_longest_chain.cpp\nSize: 1.8K\n2015-10-14 16:37");
   TGListTreeItem *item113 = fListTree1091->AddItem(item98,"root_longest_chain.cpp~");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item113->SetPictures(popen, pclose);
   item113->SetTipText("root_longest_chain.cpp~\nSize: 1.7K\n2015-10-14 15:20");
   TGListTreeItem *item114 = fListTree1091->AddItem(item98,"root_longest_chain.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item114->SetPictures(popen, pclose);
   item114->SetTipText("root_longest_chain.h\nSize: 1.5K\n2015-10-14 15:48");
   TGListTreeItem *item115 = fListTree1091->AddItem(item98,"root_longest_chain.h~");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item115->SetPictures(popen, pclose);
   item115->SetTipText("root_longest_chain.h~\nSize: 1.5K\n2015-10-14 14:57");
   TGListTreeItem *item116 = fListTree1091->AddItem(item98,"root_longest_chain.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item116->SetPictures(popen, pclose);
   item116->SetTipText("root_longest_chain.root\nSize: 4.6K\n2015-10-15 10:09");
   TGListTreeItem *item117 = fListTree1091->AddItem(item98,"root_transition_analysis");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item117->SetPictures(popen, pclose);
   item117->SetTipText("root_transition_analysis\nSize: 25.2K\n2015-10-14 16:37");
   TGListTreeItem *item118 = fListTree1091->AddItem(item98,"root_transition_analysis.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item118->SetPictures(popen, pclose);
   item118->SetTipText("root_transition_analysis.cpp\nSize: 2.2K\n2015-10-14 15:18");
   TGListTreeItem *item119 = fListTree1091->AddItem(item98,"root_transition_analysis.cpp~");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item119->SetPictures(popen, pclose);
   item119->SetTipText("root_transition_analysis.cpp~\nSize: 1.5K\n2015-10-14 14:57");
   TGListTreeItem *item120 = fListTree1091->AddItem(item98,"root_transition_analysis.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item120->SetPictures(popen, pclose);
   item120->SetTipText("root_transition_analysis.h\nSize: 1.6K\n2015-10-14 15:15");
   TGListTreeItem *item121 = fListTree1091->AddItem(item98,"root_transition_analysis.h~");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item121->SetPictures(popen, pclose);
   item121->SetTipText("root_transition_analysis.h~\nSize: 1.5K\n2015-10-14 14:57");
   TGListTreeItem *item122 = fListTree1091->AddItem(item98,"root_transition_analysis.root");
   popen = gClient->GetPicture("rootdb_t.xpm__16x16");
   pclose = gClient->GetPicture("rootdb_t.xpm__16x16");
   item122->SetPictures(popen, pclose);
   item122->SetTipText("root_transition_analysis.root\nSize: 128.7K\n2015-10-15 10:09");
   TGListTreeItem *item123 = fListTree1091->AddItem(item122,"Un_Scramble;1");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item123->SetPictures(popen, pclose);
   item123->SetTipText("Un_Scramble\nGraph");
   TGListTreeItem *item124 = fListTree1091->AddItem(item122,"New_Scramble;1");
   item124->SetPictures(popen, pclose);
   item124->SetTipText("New_Scramble\nGraph");
   TGListTreeItem *item125 = fListTree1091->AddItem(item122,"Old_Scramble;1");
   item125->SetPictures(popen, pclose);
   item125->SetTipText("Old_Scramble\nGraph");
   TGListTreeItem *item126 = fListTree1091->AddItem(item122,"Un_Scramble_short;1");
   item126->SetPictures(popen, pclose);
   item126->SetTipText("Un_Scramble_short\nGraph");
   TGListTreeItem *item127 = fListTree1091->AddItem(item122,"New_Scramble_short;1");
   item127->SetPictures(popen, pclose);
   item127->SetTipText("New_Scramble_short\nGraph");
   TGListTreeItem *item128 = fListTree1091->AddItem(item122,"Old_Scramble_short;1");
   item128->SetPictures(popen, pclose);
   item128->SetTipText("Old_Scramble_short\nGraph");
   TGListTreeItem *item129 = fListTree1091->AddItem(item98,"scramble_analysis_pre_root.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item129->SetPictures(popen, pclose);
   item129->SetTipText("scramble_analysis_pre_root.cpp\nSize: 14.9K\n2015-10-14 11:24");
   TGListTreeItem *item130 = fListTree1091->AddItem(item98,"scramble_analysis_pre_root.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item130->SetPictures(popen, pclose);
   item130->SetTipText("scramble_analysis_pre_root.h\nSize: 4.5K\n2015-10-14 11:24");
   TGListTreeItem *item131 = fListTree1091->AddItem(item98,"scramble_sim");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item131->SetPictures(popen, pclose);
   item131->SetTipText("scramble_sim\nSize: 83.2K\n2015-10-14 16:37");
   TGListTreeItem *item132 = fListTree1091->AddItem(item98,"scramble_sim.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item132->SetPictures(popen, pclose);
   item132->SetTipText("scramble_sim.cpp\nSize: 14.9K\n2015-10-14 13:49");
   TGListTreeItem *item133 = fListTree1091->AddItem(item98,"scramble_sim.cpp~");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item133->SetPictures(popen, pclose);
   item133->SetTipText("scramble_sim.cpp~\nSize: 14.9K\n2015-10-14 11:24");
   TGListTreeItem *item134 = fListTree1091->AddItem(item98,"scramble_sim.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item134->SetPictures(popen, pclose);
   item134->SetTipText("scramble_sim.h\nSize: 4.2K\n2015-10-14 13:50");
   TGListTreeItem *item135 = fListTree1091->AddItem(item98,"scramble_sim.h~");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item135->SetPictures(popen, pclose);
   item135->SetTipText("scramble_sim.h~\nSize: 4.1K\n2015-10-14 11:24");
   TGListTreeItem *item136 = fListTree1091->AddItem(item98,"transition_chain.cpp");
   popen = gClient->GetPicture("cpp_src_t.xpm__16x16");
   pclose = gClient->GetPicture("cpp_src_t.xpm__16x16");
   item136->SetPictures(popen, pclose);
   item136->SetTipText("transition_chain.cpp\nSize: 1.6K\n2015-10-14 15:20");
   TGListTreeItem *item137 = fListTree1091->AddItem(item98,"transition_chain.h");
   popen = gClient->GetPicture("h_src_t.xpm__16x16");
   pclose = gClient->GetPicture("h_src_t.xpm__16x16");
   item137->SetPictures(popen, pclose);
   item137->SetTipText("transition_chain.h\nSize: 1.3K\n2015-10-14 15:40");
   TGListTreeItem *item138 = fListTree1091->AddItem(item90,"scramble_analysis_cpp_backup");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item138->SetPictures(popen, pclose);
   TGListTreeItem *item139 = fListTree1091->AddItem(item90,"change_log.txt");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item139->SetPictures(popen, pclose);
   TGListTreeItem *item140 = fListTree1091->AddItem(item90,"change_log.txt~");
   item140->SetPictures(popen, pclose);
   TGListTreeItem *item141 = fListTree1091->AddItem(item89,"Presentations");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item141->SetPictures(popen, pclose);
   TGListTreeItem *item142 = fListTree1091->AddItem(item89,"backup_script.sh");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item142->SetPictures(popen, pclose);
   TGListTreeItem *item143 = fListTree1091->AddItem(item89,"backup_script.sh~");
   item143->SetPictures(popen, pclose);
   TGListTreeItem *item144 = fListTree1091->AddItem(item87,"Downloads");
   popen = gClient->GetPicture("ofolder_t.xpm");
   pclose = gClient->GetPicture("folder_t.xpm");
   item144->SetPictures(popen, pclose);
   TGListTreeItem *item145 = fListTree1091->AddItem(item87,"Modelsim");
   item145->SetPictures(popen, pclose);
   TGListTreeItem *item146 = fListTree1091->AddItem(item87,"Music");
   item146->SetPictures(popen, pclose);
   TGListTreeItem *item147 = fListTree1091->AddItem(item87,"Pictures");
   item147->SetPictures(popen, pclose);
   TGListTreeItem *item148 = fListTree1091->AddItem(item87,"Public");
   item148->SetPictures(popen, pclose);
   TGListTreeItem *item149 = fListTree1091->AddItem(item87,"Templates");
   item149->SetPictures(popen, pclose);
   TGListTreeItem *item150 = fListTree1091->AddItem(item87,"Videos");
   item150->SetPictures(popen, pclose);
   TGListTreeItem *item151 = fListTree1091->AddItem(item87,"altera");
   item151->SetPictures(popen, pclose);
   TGListTreeItem *item152 = fListTree1091->AddItem(item87,"amc40firmware");
   item152->SetPictures(popen, pclose);
   TGListTreeItem *item153 = fListTree1091->AddItem(item87,"local_quartus");
   item153->SetPictures(popen, pclose);
   TGListTreeItem *item154 = fListTree1091->AddItem(item87,"mgc");
   item154->SetPictures(popen, pclose);
   TGListTreeItem *item155 = fListTree1091->AddItem(item87,"root");
   item155->SetPictures(popen, pclose);
   TGListTreeItem *item156 = fListTree1091->AddItem(item87,"rootSource");
   item156->SetPictures(popen, pclose);
   TGListTreeItem *item157 = fListTree1091->AddItem(item87,"root_source");
   item157->SetPictures(popen, pclose);
   TGListTreeItem *item158 = fListTree1091->AddItem(item87,"modelsim");
   popen = gClient->GetPicture("doc_t.xpm");
   pclose = gClient->GetPicture("doc_t.xpm");
   item158->SetPictures(popen, pclose);
   TGListTreeItem *item159 = fListTree1091->AddItem(item87,"transcript");
   item159->SetPictures(popen, pclose);

   fViewPort1082->AddFrame(fListTree1091);
   fListTree1091->SetLayoutManager(new TGHorizontalLayout(fListTree1091));
   fListTree1091->MapSubwindows();
   fCanvas1081->SetContainer(fListTree1091);
   fCanvas1081->MapSubwindows();
   fCanvas1081->SetHsbPosition(0);
   fCanvas1081->SetVsbPosition(227);
   fFileBrowser1042->AddFrame(fCanvas1081, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1092 = new TGHorizontalFrame(fFileBrowser1042,238,24,kHorizontalFrame);
   TGLabel *fLabel1093 = new TGLabel(fHorizontalFrame1092,"Filter: ");
   fLabel1093->SetTextJustify(36);
   fLabel1093->SetMargins(0,0,0,0);
   fLabel1093->SetWrapLength(-1);
   fHorizontalFrame1092->AddFrame(fLabel1093, new TGLayoutHints(kLHintsLeft | kLHintsCenterY,2,2,2,2));

   gClient->GetColorByName("#ffffff",ucolor);

   // combo box
   TGComboBox *fComboBox1094 = new TGComboBox(fHorizontalFrame1092," All Files (*.*)",-1,kHorizontalFrame | kSunkenFrame | kOwnBackground);
   fComboBox1094->AddEntry(" All Files (*.*)",1);
   fComboBox1094->AddEntry(" C/C++ Files (*.c;*.cxx;*.h;...)",2);
   fComboBox1094->AddEntry(" ROOT Files (*.root)",3);
   fComboBox1094->AddEntry(" Text Files (*.txt)",4);
   fComboBox1094->Resize(197,20);
   fComboBox1094->Select(-1);
   fHorizontalFrame1092->AddFrame(fComboBox1094, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));
   fComboBox1094->Connect("Selected(int)", 0, 0, "ApplyFilter(int)");

   fFileBrowser1042->AddFrame(fHorizontalFrame1092, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,2,2,2,2));

   fCompositeFrame1041->AddFrame(fFileBrowser1042, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fFileBrowser1042->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");


   fTab1026->SetTab(0);

   fTab1026->Resize(fTab1026->GetDefaultSize());
   fVerticalFrame1022->AddFrame(fTab1026, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));

   fHorizontalFrame1021->AddFrame(fVerticalFrame1022, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandY));
   TGVSplitter *fVSplitter1028 = new TGVSplitter(fHorizontalFrame1021,4,912);
   fVSplitter1028->SetFrame(fVerticalFrame1022,kTRUE);
   fHorizontalFrame1021->AddFrame(fVSplitter1028, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandY));

   // vertical frame
   TGVerticalFrame *fVerticalFrame1023 = new TGVerticalFrame(fHorizontalFrame1021,1426,912,kVerticalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1024 = new TGHorizontalFrame(fVerticalFrame1023,1422,683,kHorizontalFrame);

   // tab widget
   TGTab *fTab1029 = new TGTab(fHorizontalFrame1024,1422,683);

   // container of "Canvas_1"
   TGCompositeFrame *fCompositeFrame1111;
   fCompositeFrame1111 = fTab1029->AddTab("Canvas_1");
   fCompositeFrame1111->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1111));

   // composite frame
   TGCompositeFrame *fRootCanvas1112 = new TGCompositeFrame(fCompositeFrame1111,1418,657,kVerticalFrame);
   TGHorizontal3DLine *fHorizontal3DLine1130 = new TGHorizontal3DLine(fRootCanvas1112,700,2);
   fRootCanvas1112->AddFrame(fHorizontal3DLine1130, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

   // dockable frame
   TGDockableFrame *fDockableFrame1131 = new TGDockableFrame(fRootCanvas1112);

   // next lines belong to the dockable frame widget
   fDockableFrame1131->EnableUndock(kTRUE);
   fDockableFrame1131->EnableHide(kFALSE);
   fDockableFrame1131->SetWindowName("ToolBar: Canvas_1");
   fDockableFrame1131->DockContainer();

   fRootCanvas1112->AddFrame(fDockableFrame1131, new TGLayoutHints(kLHintsExpandX));
   TGHorizontal3DLine *fHorizontal3DLine1136 = new TGHorizontal3DLine(fRootCanvas1112,700,2);
   fRootCanvas1112->AddFrame(fHorizontal3DLine1136, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

   // composite frame
   TGCompositeFrame *fCompositeFrame1137 = new TGCompositeFrame(fRootCanvas1112,1418,657,kHorizontalFrame);

   // composite frame
   TGCompositeFrame *fCompositeFrame1138 = new TGCompositeFrame(fCompositeFrame1137,175,475,kFixedWidth);
   fCompositeFrame1138->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1138));

   fCompositeFrame1137->AddFrame(fCompositeFrame1138, new TGLayoutHints(kLHintsLeft | kLHintsExpandY));

   // canvas widget
   TGCanvas *fCanvas1139 = new TGCanvas(fCompositeFrame1137,1418,657,kSunkenFrame);

   // canvas viewport
   TGViewPort *fViewPort1140 = fCanvas1139->GetViewPort();

   // canvas container
   Int_t canvasID = gVirtualX->InitWindow((ULong_t)fCanvas1139->GetId());
   Window_t winC = gVirtualX->GetWindowID(canvasID);
   TGCompositeFrame *fCompositeFrame1149 = new TGCompositeFrame(gClient,winC,fViewPort1140);
   fViewPort1140->AddFrame(fCompositeFrame1149);
   fCompositeFrame1149->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1149));
   fCompositeFrame1149->MapSubwindows();
   fCanvas1139->SetContainer(fCompositeFrame1149);
   fCanvas1139->MapSubwindows();
   fCompositeFrame1137->AddFrame(fCanvas1139, new TGLayoutHints(kLHintsRight | kLHintsExpandX | kLHintsExpandY));

   fRootCanvas1112->AddFrame(fCompositeFrame1137, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));

   // status bar
   TGStatusBar *fStatusBar1152 = new TGStatusBar(fRootCanvas1112,10,18);
   Int_t partsusBar1152[] = {33,10,10,47};
   fStatusBar1152->SetParts(partsusBar1152,4);
   fRootCanvas1112->AddFrame(fStatusBar1152, new TGLayoutHints(kLHintsLeft | kLHintsBottom | kLHintsExpandX,2,2,1,1));

   fCompositeFrame1111->AddFrame(fRootCanvas1112, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fRootCanvas1112->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");

   TGTabElement *tab0 = fTab1029->GetTabTab(0);
   tab0->ShowClose(kTRUE);

   // container of "Editor 1"
   TGCompositeFrame *fCompositeFrame1160;
   fCompositeFrame1160 = fTab1029->AddTab("Editor 1");
   fCompositeFrame1160->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1160));

   // composite frame
   TGCompositeFrame *fTextEditor1161 = new TGCompositeFrame(fCompositeFrame1160,1418,657,kVerticalFrame);
   TGHorizontal3DLine *fHorizontal3DLine1174 = new TGHorizontal3DLine(fTextEditor1161,1418,2);
   fTextEditor1161->AddFrame(fHorizontal3DLine1174, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,2,2));

   // tool bar
   TGToolBar *fToolBar1175 = new TGToolBar(fTextEditor1161,1418,23,kHorizontalFrame);

   ToolBarData_t t;
   t.fPixmap = "ed_new.png";
   t.fTipText = "New File";
   t.fStayDown = kFALSE;
   t.fId = 1;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,8);
   t.fPixmap = "ed_open.png";
   t.fTipText = "Open File";
   t.fStayDown = kFALSE;
   t.fId = 2;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   t.fPixmap = "ed_save.png";
   t.fTipText = "Save File";
   t.fStayDown = kFALSE;
   t.fId = 3;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   t.fPixmap = "ed_saveas.png";
   t.fTipText = "Save File As...";
   t.fStayDown = kFALSE;
   t.fId = 4;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   t.fPixmap = "ed_print.png";
   t.fTipText = "Print";
   t.fStayDown = kFALSE;
   t.fId = 5;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,8);
   t.fPixmap = "ed_cut.png";
   t.fTipText = "Cut selection";
   t.fStayDown = kFALSE;
   t.fId = 6;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,8);
   TGButton *fPictureButton1191 = t.fButton;
   fPictureButton1191->SetState(kButtonDisabled);
   t.fPixmap = "ed_copy.png";
   t.fTipText = "Copy selection";
   t.fStayDown = kFALSE;
   t.fId = 7;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   TGButton *fPictureButton1194 = t.fButton;
   fPictureButton1194->SetState(kButtonDisabled);
   t.fPixmap = "ed_paste.png";
   t.fTipText = "Paste selection";
   t.fStayDown = kFALSE;
   t.fId = 8;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   TGButton *fPictureButton1197 = t.fButton;
   fPictureButton1197->SetState(kButtonDisabled);
   t.fPixmap = "ed_delete.png";
   t.fTipText = "Delete selection";
   t.fStayDown = kFALSE;
   t.fId = 9;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   TGButton *fPictureButton1200 = t.fButton;
   fPictureButton1200->SetState(kButtonDisabled);
   t.fPixmap = "ed_find.png";
   t.fTipText = "Find...";
   t.fStayDown = kFALSE;
   t.fId = 10;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,8);
   t.fPixmap = "ed_findnext.png";
   t.fTipText = "Find next";
   t.fStayDown = kFALSE;
   t.fId = 11;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   t.fPixmap = "ed_goto.png";
   t.fTipText = "Goto...";
   t.fStayDown = kFALSE;
   t.fId = 12;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   t.fPixmap = "ed_compile.png";
   t.fTipText = "Compile Macro";
   t.fStayDown = kFALSE;
   t.fId = 13;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,8);
   t.fPixmap = "ed_execute.png";
   t.fTipText = "Execute Macro";
   t.fStayDown = kFALSE;
   t.fId = 14;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   t.fPixmap = "ed_interrupt.png";
   t.fTipText = "Interrupt";
   t.fStayDown = kFALSE;
   t.fId = 15;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,0);
   t.fPixmap = "ed_help.png";
   t.fTipText = "Help Contents";
   t.fStayDown = kFALSE;
   t.fId = 16;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,8);
   t.fPixmap = "ed_quit.png";
   t.fTipText = "Close Editor";
   t.fStayDown = kFALSE;
   t.fId = 17;
   t.fButton = 0;
   fToolBar1175->AddButton(fTextEditor1161,&t,8);
   TGButton *fPictureButton1224 = t.fButton;
   fPictureButton1224->SetState(kButtonDisabled);
   fTextEditor1161->AddFrame(fToolBar1175, new TGLayoutHints(kLHintsTop | kLHintsExpandX));
   TGHorizontal3DLine *fHorizontal3DLine1239 = new TGHorizontal3DLine(fTextEditor1161,1418,2);
   fTextEditor1161->AddFrame(fHorizontal3DLine1239, new TGLayoutHints(kLHintsTop | kLHintsExpandX,0,0,2,2));
   TGTextEdit *fTextEdit1240 = new TGTextEdit(fTextEditor1161,1418,601);
   fTextEdit1240->LoadFile("TxtEdit1240");
   fTextEditor1161->AddFrame(fTextEdit1240, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fTextEdit1240->Connect("DataDropped(char*)", 0, 0, "DataDropped(char*)");

   // status bar
   TGStatusBar *fStatusBar1251 = new TGStatusBar(fTextEditor1161,1418,18);
   Int_t partsusBar1251[] = {75,25};
   fStatusBar1251->SetParts(partsusBar1251,2);
   fStatusBar1251->SetText("Untitled",0);
   fStatusBar1251->SetText("Ln 0, Ch 0",1);
   fTextEditor1161->AddFrame(fStatusBar1251, new TGLayoutHints(kLHintsBottom | kLHintsExpandX,0,0,3,0));

   fCompositeFrame1160->AddFrame(fTextEditor1161, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fTextEditor1161->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");

   TGTabElement *tab1 = fTab1029->GetTabTab(1);
   tab1->ShowClose(kTRUE);

   // container of "Canvas_1_n2"
   TGCompositeFrame *fCompositeFrame1316;
   fCompositeFrame1316 = fTab1029->AddTab("Canvas_1_n2");
   fCompositeFrame1316->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1316));

   // composite frame
   TGCompositeFrame *fRootCanvas1317 = new TGCompositeFrame(fCompositeFrame1316,1418,657,kVerticalFrame);
   TGHorizontal3DLine *fHorizontal3DLine1335 = new TGHorizontal3DLine(fRootCanvas1317,700,2);
   fRootCanvas1317->AddFrame(fHorizontal3DLine1335, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

   // dockable frame
   TGDockableFrame *fDockableFrame1336 = new TGDockableFrame(fRootCanvas1317);

   // next lines belong to the dockable frame widget
   fDockableFrame1336->EnableUndock(kTRUE);
   fDockableFrame1336->EnableHide(kFALSE);
   fDockableFrame1336->SetWindowName("ToolBar: Canvas_1_n2");
   fDockableFrame1336->DockContainer();

   fRootCanvas1317->AddFrame(fDockableFrame1336, new TGLayoutHints(kLHintsExpandX));
   TGHorizontal3DLine *fHorizontal3DLine1341 = new TGHorizontal3DLine(fRootCanvas1317,700,2);
   fRootCanvas1317->AddFrame(fHorizontal3DLine1341, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

   // composite frame
   TGCompositeFrame *fCompositeFrame1342 = new TGCompositeFrame(fRootCanvas1317,1418,657,kHorizontalFrame);

   // composite frame
   TGCompositeFrame *fCompositeFrame1343 = new TGCompositeFrame(fCompositeFrame1342,175,475,kFixedWidth);
   fCompositeFrame1343->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1343));

   fCompositeFrame1342->AddFrame(fCompositeFrame1343, new TGLayoutHints(kLHintsLeft | kLHintsExpandY));

   // canvas widget
   TGCanvas *fCanvas1344 = new TGCanvas(fCompositeFrame1342,1418,657,kSunkenFrame);

   // canvas viewport
   TGViewPort *fViewPort1345 = fCanvas1344->GetViewPort();

   // canvas container
   Int_t canvasID = gVirtualX->InitWindow((ULong_t)fCanvas1344->GetId());
   Window_t winC = gVirtualX->GetWindowID(canvasID);
   TGCompositeFrame *fCompositeFrame1354 = new TGCompositeFrame(gClient,winC,fViewPort1345);
   fViewPort1345->AddFrame(fCompositeFrame1354);
   fCompositeFrame1354->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1354));
   fCompositeFrame1354->MapSubwindows();
   fCanvas1344->SetContainer(fCompositeFrame1354);
   fCanvas1344->MapSubwindows();
   fCompositeFrame1342->AddFrame(fCanvas1344, new TGLayoutHints(kLHintsRight | kLHintsExpandX | kLHintsExpandY));

   fRootCanvas1317->AddFrame(fCompositeFrame1342, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));

   // status bar
   TGStatusBar *fStatusBar1357 = new TGStatusBar(fRootCanvas1317,10,18);
   Int_t partsusBar1357[] = {33,10,10,47};
   fStatusBar1357->SetParts(partsusBar1357,4);
   fRootCanvas1317->AddFrame(fStatusBar1357, new TGLayoutHints(kLHintsLeft | kLHintsBottom | kLHintsExpandX,2,2,1,1));

   fCompositeFrame1316->AddFrame(fRootCanvas1317, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fRootCanvas1317->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");

   TGTabElement *tab2 = fTab1029->GetTabTab(2);
   tab2->ShowClose(kTRUE);

   // container of "Canvas_1_n3"
   TGCompositeFrame *fCompositeFrame1405;
   fCompositeFrame1405 = fTab1029->AddTab("Canvas_1_n3");
   fCompositeFrame1405->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1405));

   // composite frame
   TGCompositeFrame *fRootCanvas1406 = new TGCompositeFrame(fCompositeFrame1405,1418,657,kVerticalFrame);
   TGHorizontal3DLine *fHorizontal3DLine1424 = new TGHorizontal3DLine(fRootCanvas1406,700,2);
   fRootCanvas1406->AddFrame(fHorizontal3DLine1424, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

   // dockable frame
   TGDockableFrame *fDockableFrame1425 = new TGDockableFrame(fRootCanvas1406);

   // next lines belong to the dockable frame widget
   fDockableFrame1425->EnableUndock(kTRUE);
   fDockableFrame1425->EnableHide(kFALSE);
   fDockableFrame1425->SetWindowName("ToolBar: Transition Count for New and Old Scrambler");
   fDockableFrame1425->DockContainer();

   fRootCanvas1406->AddFrame(fDockableFrame1425, new TGLayoutHints(kLHintsExpandX));
   TGHorizontal3DLine *fHorizontal3DLine1430 = new TGHorizontal3DLine(fRootCanvas1406,700,2);
   fRootCanvas1406->AddFrame(fHorizontal3DLine1430, new TGLayoutHints(kLHintsTop | kLHintsExpandX));

   // composite frame
   TGCompositeFrame *fCompositeFrame1431 = new TGCompositeFrame(fRootCanvas1406,1418,657,kHorizontalFrame);

   // composite frame
   TGCompositeFrame *fCompositeFrame1432 = new TGCompositeFrame(fCompositeFrame1431,175,475,kFixedWidth);
   fCompositeFrame1432->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1432));

   fCompositeFrame1431->AddFrame(fCompositeFrame1432, new TGLayoutHints(kLHintsLeft | kLHintsExpandY));

   // canvas widget
   TGCanvas *fCanvas1433 = new TGCanvas(fCompositeFrame1431,1418,657,kSunkenFrame);

   // canvas viewport
   TGViewPort *fViewPort1434 = fCanvas1433->GetViewPort();

   // canvas container
   Int_t canvasID = gVirtualX->InitWindow((ULong_t)fCanvas1433->GetId());
   Window_t winC = gVirtualX->GetWindowID(canvasID);
   TGCompositeFrame *fCompositeFrame1443 = new TGCompositeFrame(gClient,winC,fViewPort1434);
   fViewPort1434->AddFrame(fCompositeFrame1443);
   fCompositeFrame1443->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1443));
   fCompositeFrame1443->MapSubwindows();
   fCanvas1433->SetContainer(fCompositeFrame1443);
   fCanvas1433->MapSubwindows();
   fCompositeFrame1431->AddFrame(fCanvas1433, new TGLayoutHints(kLHintsRight | kLHintsExpandX | kLHintsExpandY));

   fRootCanvas1406->AddFrame(fCompositeFrame1431, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));

   // status bar
   TGStatusBar *fStatusBar1446 = new TGStatusBar(fRootCanvas1406,10,18);
   Int_t partsusBar1446[] = {33,10,10,47};
   fStatusBar1446->SetParts(partsusBar1446,4);
   fRootCanvas1406->AddFrame(fStatusBar1446, new TGLayoutHints(kLHintsLeft | kLHintsBottom | kLHintsExpandX,2,2,1,1));

   fCompositeFrame1405->AddFrame(fRootCanvas1406, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fRootCanvas1406->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");

   TGTabElement *tab3 = fTab1029->GetTabTab(3);
   tab3->ShowClose(kTRUE);

   fTab1029->SetTab(3);

   fTab1029->Resize(fTab1029->GetDefaultSize());
   fHorizontalFrame1024->AddFrame(fTab1029, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));
   fTab1029->Connect("CloseTab(int)", 0, 0, "CloseTab(int)");

   fVerticalFrame1023->AddFrame(fHorizontalFrame1024, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));
   TGHSplitter *fHSplitter1031 = new TGHSplitter(fVerticalFrame1023,1426,4);
   fVerticalFrame1023->AddFrame(fHSplitter1031, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX));

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1025 = new TGHorizontalFrame(fVerticalFrame1023,1426,221,kHorizontalFrame | kFixedHeight);

   // tab widget
   TGTab *fTab1032 = new TGTab(fHorizontalFrame1025,1422,217);

   // container of "Command"
   TGCompositeFrame *fCompositeFrame1256;
   fCompositeFrame1256 = fTab1032->AddTab("Command");
   fCompositeFrame1256->SetLayoutManager(new TGVerticalLayout(fCompositeFrame1256));

   // composite frame
   TGCompositeFrame *fCommandPlugin1257 = new TGCompositeFrame(fCompositeFrame1256,1418,191,kVerticalFrame);

   // horizontal frame
   TGHorizontalFrame *fHorizontalFrame1258 = new TGHorizontalFrame(fCommandPlugin1257,1412,25,kHorizontalFrame);

   gClient->GetColorByName("#ffffff",ucolor);

   // combo box
   TGComboBox *fComboBox1259 = new TGComboBox(fHorizontalFrame1258,"",1,kHorizontalFrame | kSunkenFrame | kOwnBackground);
   fComboBox1259->AddEntry("Un_Scrambled->SetTitle->(\"hello world\");",0);
   fComboBox1259->AddEntry("Un_Scrambled->SetTitle->(\"hello world\")",0);
   fComboBox1259->AddEntry("Canvas_1_n3->SetTitle(\"Transition Count for New and Old Scrambler\");",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry("new TBrowser",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry(".x draw_transition_graph.C ",0);
   fComboBox1259->AddEntry("TBrowser a",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry(".x draw_transition_graph.C ",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry(".x draw_transition_graph.C ",0);
   fComboBox1259->AddEntry(".x draw_transition_graph.C ",0);
   fComboBox1259->AddEntry(".x draw_transition_graph.C ",0);
   fComboBox1259->AddEntry(".x draw_transition_graph.C ",0);
   fComboBox1259->AddEntry("TBrowser a",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry(".q",0);
   fComboBox1259->AddEntry("q",0);
   fComboBox1259->AddEntry("Canvas_1_n3->SetTitle(\"Transition Count for New and Old Scrambler\");",32);
   fComboBox1259->AddEntry("Un_Scrambled->SetTitle->(\"hello world\")",34);
   fComboBox1259->AddEntry("Un_Scrambled->SetTitle->(\"hello world\");",36);
   fComboBox1259->Resize(1295,23);
   fComboBox1259->Select(36);
   fHorizontalFrame1258->AddFrame(fComboBox1259, new TGLayoutHints(kLHintsRight | kLHintsCenterY | kLHintsExpandX,5,5,1,1));

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   TGGC   *uGC;           // will reflect user GC changes
   // graphics context changes
   GCValues_t vall1270;
   vall1270.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall1270.fForeground);
   gClient->GetColorByName("#e8e8e8",vall1270.fBackground);
   vall1270.fFillStyle = kFillSolid;
   vall1270.fFont = ufont->GetFontHandle();
   vall1270.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall1270, kTRUE);
   TGLabel *fLabel1270 = new TGLabel(fHorizontalFrame1258,"Command (local):",uGC->GetGC());
   fLabel1270->SetTextJustify(36);
   fLabel1270->SetMargins(0,0,0,0);
   fLabel1270->SetWrapLength(-1);
   fHorizontalFrame1258->AddFrame(fLabel1270, new TGLayoutHints(kLHintsRight | kLHintsCenterY,5,5,1,1));

   fCommandPlugin1257->AddFrame(fHorizontalFrame1258, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX,3,3,3,3));
   TGTextView *fTextView1271 = new TGTextView(fCommandPlugin1257,1412,154);
   fTextView1271->LoadFile("/tmp/command.21473.log");
   fCommandPlugin1257->AddFrame(fTextView1271, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,3,3,3,3));

   fCompositeFrame1256->AddFrame(fCommandPlugin1257, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fCommandPlugin1257->Connect("ProcessedConfigure(Event_t*)", 0, 0, "Layout()");


   fTab1032->SetTab(0);

   fTab1032->Resize(fTab1032->GetDefaultSize());
   fHorizontalFrame1025->AddFrame(fTab1032, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2));

   fVerticalFrame1023->AddFrame(fHorizontalFrame1025, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX));
   fHSplitter1031->SetFrame(fHorizontalFrame1025,kFALSE);

   fHorizontalFrame1021->AddFrame(fVerticalFrame1023, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   fVerticalFrame1010->AddFrame(fHorizontalFrame1021, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   fRootBrowser1009->AddFrame(fVerticalFrame1010, new TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY));

   // status bar
   TGStatusBar *fStatusBar1034 = new TGStatusBar(fRootBrowser1009,1680,18);
   Int_t partsusBar1034[] = {33,10,10,47};
   fStatusBar1034->SetParts(partsusBar1034,4);
   fStatusBar1034->SetText("",0);
   fStatusBar1034->SetText("",1);
   fStatusBar1034->SetText("",2);
   fStatusBar1034->SetText("",3);
   fRootBrowser1009->AddFrame(fStatusBar1034, new TGLayoutHints(kLHintsBottom | kLHintsExpandX));

   fRootBrowser1009->SetWindowName("ROOT Object Browser");
   fRootBrowser1009->SetIconName("ROOT Object Browser");
   fRootBrowser1009->SetIconPixmap("rootdb_s.xpm");
   fRootBrowser1009->SetClassHints("ROOT","Browser");
   fRootBrowser1009->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fRootBrowser1009->SetWMSizeHints(600,350,10000,10000,2,2);
   fRootBrowser1009->MapSubwindows();
   fMenuBar1122->UnmapWindow();
   fMenuBar1167->UnmapWindow();
   fMenuBar1327->UnmapWindow();
   fHorizontalFrame1020->UnmapWindow();
   fHorizontal3DLine1130->UnmapWindow();
   fDockableFrame1131->UnmapWindow();
   fHorizontal3DLine1136->UnmapWindow();
   fCompositeFrame1138->UnmapWindow();
   fStatusBar1152->UnmapWindow();
   fHorizontal3DLine1335->UnmapWindow();
   fDockableFrame1336->UnmapWindow();
   fHorizontal3DLine1341->UnmapWindow();
   fCompositeFrame1343->UnmapWindow();
   fStatusBar1357->UnmapWindow();
   fHorizontal3DLine1424->UnmapWindow();
   fDockableFrame1425->UnmapWindow();
   fHorizontal3DLine1430->UnmapWindow();
   fCompositeFrame1432->UnmapWindow();
   fStatusBar1446->UnmapWindow();

   fRootBrowser1009->Resize(fRootBrowser1009->GetDefaultSize());
   fRootBrowser1009->MapWindow();
   fRootBrowser1009->Resize(1680,957);
}  

void ToggleSort()
{
   std::cout << "Slot ToggleSort()" << std::endl; 
}

void RequestFilter()
{
   std::cout << "Slot RequestFilter()" << std::endl; 
}

void Refresh()
{
   std::cout << "Slot Refresh()" << std::endl; 
}

void ApplyFilter(int par1)
{
   std::cout << "Slot ApplyFilter(int " << par1 << ")" << std::endl; 
}

void Layout()
{
   std::cout << "Slot Layout()" << std::endl; 
}

void DataDropped(char* par2)
{
   std::cout << "Slot DataDropped(char* " << par2 << ")" << std::endl; 
}

void CloseTab(int par3)
{
   std::cout << "Slot CloseTab(int " << par3 << ")" << std::endl; 
}
