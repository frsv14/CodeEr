// For compilers that support precompilation
#ifndef MAIN_CPP
#define MAIN_CPP
#include <wx/wx.h>
#include <wx/wxprec.h>
#include "main.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()


MyFrame::MyFrame(const wxString& title,
                 const wxPoint& pos,
                 const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu* menuFile = new wxMenu;

    menuFile->Append(
        ID_Hello,
        "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item"
    );

    menuFile->Append(
        0,
        "@test",
        "Test string shown in status bar for this menu item"
    );

    menuFile->Append(
        0,
        "@test",
        "Test string shown in status bar for this menu item"
    );

    menuFile->Append(
        0,
        "@test",
        "Test string shown in status bar for this menu item"
    );

    menuFile->Append(
        0,
        "@test",
        "Test string shown in status bar for this menu item"
    );

    menuFile->Append(
        0,
        "@test",
        "Test string shown in status bar for this menu item"
    );

    menuFile->Append(
        0,
        "@test",
        "Test string shown in status bar for this menu item"
    );



    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;

    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();

    SetStatusText("Hello from wxWidgets!");

    // Panel setup

    wxPanel* panel_main = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wxPanel* panel_console = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wxPanel* panel_files = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wxPanel* panel_prod = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    panel_main->SetBackgroundColour(wxColour(100, 100, 100));
    panel_console->SetBackgroundColour(wxColour(50, 50, 50));
    panel_files->SetBackgroundColour(wxColour(100, 100, 200));
    panel_prod->SetBackgroundColour(wxColour(50, 255, 50));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL); // use splitters intead of sizers for more features
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxVERTICAL);

    sizer->Add(panel_main, 2, wxEXPAND | (wxLEFT & wxRIGHT), 10);
    sizer->Add(panel_console, 1, wxEXPAND | (wxLEFT & wxRIGHT), 10);
    sizer_2->Add(panel_files, 1, wxEXPAND | (wxLEFT & wxRIGHT), 10);
    sizer_2->Add(panel_prod, 1, wxEXPAND | (wxLEFT & wxRIGHT), 10);


    wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    sizer_3->Add(sizer_2, 1, wxEXPAND, 10);
    sizer_3->Add(sizer, 3, wxEXPAND, 10);

    this->SetSizerAndFit(sizer_3);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(
        "This is a wxWidgets Hello World sample",
        "About Hello World",
        wxOK | wxICON_INFORMATION
    );
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

#endif