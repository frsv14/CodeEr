// For compilers that support precompilation
#ifndef MAIN_CPP
#define MAIN_CPP
#include <wx/wx.h>
#include <wx/wxprec.h>
#include <wx/splitter.h>
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
    wxSplitterWindow* splitter1 = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_THIN_SASH | wxSP_LIVE_UPDATE);
    wxSplitterWindow* splitter2 = new wxSplitterWindow(splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_THIN_SASH | wxSP_LIVE_UPDATE);
    wxSplitterWindow* splitter3 = new wxSplitterWindow(splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_THIN_SASH | wxSP_LIVE_UPDATE);

    wxWindow* panel_main = new wxWindow(splitter1, wxID_ANY, wxPoint(0, 0), wxDefaultSize);
    wxWindow* panel_console = new wxWindow(splitter2, wxID_ANY, wxPoint(0, 0), wxDefaultSize);
    wxWindow* panel_files = new wxWindow(splitter3, wxID_ANY, wxPoint(0, 0), wxDefaultSize);
    wxWindow* panel_prod = new wxWindow(splitter3, wxID_ANY, wxPoint(0, 0), wxDefaultSize);

    panel_main->SetBackgroundColour(wxColour(0, 255, 0)); //red
    panel_console->SetBackgroundColour(wxColour(255, 0, 0)); //green
    panel_files->SetBackgroundColour(wxColour(100, 12, 200)); // purple
    panel_prod->SetBackgroundColour(wxColour(255, 255, 50)); // yellow

    splitter1->SplitHorizontally(splitter2, panel_main);
    splitter2->SplitVertically(splitter3, panel_console);
    splitter3->SplitVertically(panel_files, panel_prod);

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