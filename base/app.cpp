#include "app.h"

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(
        "Hello World",
        wxPoint(1000, 1000),
        wxSize(1000, 1000)
    );

    frame->Show(true);

    return true;
}