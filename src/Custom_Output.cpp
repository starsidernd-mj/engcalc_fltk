#include "Custom_Output.h"

Custom_Output::Custom_Output(int X, int Y, int W, int H, const char* L) : Fl_Output(X, Y, W, H, L), last_value(nullptr)
{
    //ctor
    last_value = strdup(value());
}

Custom_Output::~Custom_Output()
{
    //dtor
    free(last_value);
}

void Custom_Output::set_change_callback(Fl_Callback* cb, void* data) {
    change_callback = cb;
    user_data = data;
}

int Custom_Output::handle(int event) {
    int ret = Fl_Output::handle(event);
    if(event == FL_KEYDOWN || event == FL_KEYUP || event == FL_PASTE || event == FL_UNFOCUS) {
        change_callback(this, user_data);
        /*if(strcmp(value(), last_value) != 0) {
            free(last_value);
            last_value = strdup(value());
            if(change_callback) {
                change_callback(this, user_data);
            }
        }*/
    }
    return ret;
}
