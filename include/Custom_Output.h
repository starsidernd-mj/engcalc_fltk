#ifndef CUSTOM_OUTPUT_H
#define CUSTOM_OUTPUT_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <iostream>
#include <cstring>

class Custom_Output : public Fl_Output
{
    public:
        Custom_Output(int X, int Y, int W, int H, const char* L = 0);
        virtual ~Custom_Output();

        void set_change_callback(Fl_Callback* cb, void* data);

    protected:
        int handle(int event) override;

    private:
        char* last_value;
        Fl_Callback* change_callback = nullptr;
        void* user_data = nullptr;
};

#endif // CUSTOM_OUTPUT_H
