#ifndef APP_H
#define APP_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
    #include "/home/frsv/CoderEr/CodeEr/main.h"
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};


wxIMPLEMENT_APP(MyApp);

#endif