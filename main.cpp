#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/fl_message.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Text_Display.H>

#include <unistd.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iostream>

#include "Bin.h"
#include "Dec.h"
#include "Hex.h"
#include "Oct.h"
#include "Custom_Output.h"

Fl_Window *window;

Fl_Box *back_box;

// Numerical
Fl_Button *num0_btn;
Fl_Button *num1_btn;
Fl_Button *num2_btn;
Fl_Button *num3_btn;
Fl_Button *num4_btn;
Fl_Button *num5_btn;
Fl_Button *num6_btn;
Fl_Button *num7_btn;
Fl_Button *num8_btn;
Fl_Button *num9_btn;

Fl_Button *numA_btn;
Fl_Button *numB_btn;
Fl_Button *numC_btn;
Fl_Button *numD_btn;
Fl_Button *numE_btn;
Fl_Button *numF_btn;

// Buttons
Fl_Button *op_lbrace_btn;
Fl_Button *op_rbrace_btn;

Fl_Button *op_plus_btn;
Fl_Button *op_minus_btn;
Fl_Button *op_mult_btn;
Fl_Button *op_div_btn;

Fl_Button *op_neg_btn;
Fl_Button *op_dec_btn;

Fl_Button *op_equal_btn;

Fl_Button *op_lshift_btn;
Fl_Button *op_rshift_btn;

Fl_Button *op_and_btn;
Fl_Button *op_or_btn;
Fl_Button *op_not_btn;
Fl_Button *op_xor_btn;

Fl_Button *clear_btn;

Fl_Button *empty_btn;

Fl_Output *res_out_disp;
Fl_Output *bin_out_disp;
Fl_Output *dec_out_disp;
Fl_Output *hex_out_disp;
Fl_Output *oct_out_disp;

Custom_Output *res_out_tdisp;

// Mode variables

enum MODE {
    MODE_DEC,
    MODE_HEX,
    MODE_OCT,
    MODE_BIN
};

MODE current_mode = MODE_DEC;

// Size and spacing variables, methods

int h_cnt = 10;
int v_cnt = 40;

int h_inc_s = 45;
int v_inc_s = 50;

void inc_h_cnt(int val) {
    h_cnt += val;
}

void inc_v_cnt(int val) {
    v_cnt += val;
    h_cnt = 10;
}

// Operations here

enum OPS {
    OP_ADD,
    OP_SUB,
    OP_MULT,
    OP_DIV,
    OP_EQUAL,
    OP_NEG,
    OP_LSHIFT,
    OP_RSHIFT,
    OP_AND,
    OP_OR,
    OP_NOT,
    OP_XOR,
    OP_CLEAR
};

void op_add();
void op_sub();
void op_mlt();
void op_div();

void op_equal();

void op_neg();

void op_lshift();
void op_rshift();

void op_and();
void op_or();
void op_not();
void op_xor();

void op_clear();

// Methods for setting and getting value in hex, dec, oct, or bin format

void get_hex();
void get_dec();
void get_oct();
void get_bin();

void set_mode(MODE data) {
    switch(data) {
        case MODE_BIN: {
            //std::cout << "Entered MODE_BIN" << std::endl;
            num0_btn->activate();
            num1_btn->activate();
            num2_btn->deactivate();
            num3_btn->deactivate();
            num4_btn->deactivate();
            num5_btn->deactivate();
            num6_btn->deactivate();
            num7_btn->deactivate();
            num8_btn->deactivate();
            num9_btn->deactivate();

            numA_btn->deactivate();
            numB_btn->deactivate();
            numC_btn->deactivate();
            numD_btn->deactivate();
            numE_btn->deactivate();
            numF_btn->deactivate();
        } break;
        case MODE_DEC: {
            //std::cout << "Entered MODE_DEC" << std::endl;
            num0_btn->activate();
            num1_btn->activate();
            num2_btn->activate();
            num3_btn->activate();
            num4_btn->activate();
            num5_btn->activate();
            num6_btn->activate();
            num7_btn->activate();
            num8_btn->activate();
            num9_btn->activate();

            numA_btn->deactivate();
            numB_btn->deactivate();
            numC_btn->deactivate();
            numD_btn->deactivate();
            numE_btn->deactivate();
            numF_btn->deactivate();
        } break;
        case MODE_HEX: {
            //std::cout << "Entered MODE_HEX" << std::endl;
            num0_btn->activate();
            num1_btn->activate();
            num2_btn->activate();
            num3_btn->activate();
            num4_btn->activate();
            num5_btn->activate();
            num6_btn->activate();
            num7_btn->activate();
            num8_btn->activate();
            num9_btn->activate();

            numA_btn->activate();
            numB_btn->activate();
            numC_btn->activate();
            numD_btn->activate();
            numE_btn->activate();
            numF_btn->activate();
        } break;
        case MODE_OCT: {
            //std::cout << "Entered MODE_OCT" << std::endl;
            num0_btn->activate();
            num1_btn->activate();
            num2_btn->activate();
            num3_btn->activate();
            num4_btn->activate();
            num5_btn->activate();
            num6_btn->activate();
            num7_btn->activate();
            num8_btn->activate();
            num9_btn->activate();

            numA_btn->activate();
            numB_btn->activate();
            numC_btn->activate();
            numD_btn->activate();
            numE_btn->activate();
            numF_btn->activate();
        } break;
    }
}

// Callbacks here

void listen_key_input(Fl_Widget* widget, void* data) {
    Fl_Window* window = (Fl_Window*)widget;
}

void op_callback(Fl_Widget* widget, long int data) {
    Fl_Button* button = (Fl_Button*)widget;
    std::cout << "Op callback: " << data << std::endl;
    switch(data) {
        case OP_ADD : {

        } break;
        case OP_SUB : {

        } break;
        case OP_MULT : {

        } break;
        case OP_DIV : {

        } break;
        case OP_EQUAL : {

        } break;
        case OP_NEG : {

        } break;
        case OP_LSHIFT : {

        } break;
        case OP_RSHIFT : {

        } break;
        case OP_AND : {

        } break;
        case OP_OR : {

        } break;
        case OP_NOT : {

        } break;
        case OP_XOR : {

        } break;
        case OP_CLEAR : {

        } break;
        default : {} break;
    }
}

void op_num_callback(Fl_Widget* widget, long int data) {
    Fl_Button* button = (Fl_Button*)widget;
    std::cout << "Btn pressed: " << data << std::endl;
}

void result_output_update_callback(Fl_Widget* widget, void* data) {
    Fl_Output* output = (Fl_Output*)widget;
    std::cout << "Value of result output updated: " << output->value() << std::endl;
}

void num_type_callback(Fl_Widget* widget, long int data) {
    Fl_Output* output = (Fl_Output*)widget;
    //std::cout << "Num type selected: " << output->label() << ":" << data << std::endl;

    dec_out_disp->textcolor(FL_BLACK);
    bin_out_disp->textcolor(FL_BLACK);
    hex_out_disp->textcolor(FL_BLACK);
    oct_out_disp->textcolor(FL_BLACK);

    dec_out_disp->labelcolor(FL_BLACK);
    bin_out_disp->labelcolor(FL_BLACK);
    hex_out_disp->labelcolor(FL_BLACK);
    oct_out_disp->labelcolor(FL_BLACK);

    output->textcolor(FL_BLUE);
    output->labelcolor(FL_BLUE);

    current_mode = (MODE)data;

    set_mode(current_mode);

    window->redraw();
}

/*void on_top_toggle_callback(Fl_Widget* widget, void* data) {
    Fl_Check_Button* checkbox = (Fl_Check_Button*)widget;
    Fl_Window* window = (Fl_Window*)data;
    bool on_top = checkbox->value();
    set_window_always_on_top(window, on_top);
}*/

void output_changed_callback(Fl_Widget* widget, void* user_data) {
    Custom_Output* output = static_cast<Custom_Output*>(widget);
    std::cout << "Output changed! New value: " << output->value() << std::endl;
}

// Main here

int main(int argc, char **argv) {
    window = new Fl_Window(285, 430, "Programming Calc");
    window->color(FL_WHITE);
    //window->callback(listen_key_input);

    res_out_tdisp = new Custom_Output(0, 5, 285, 40);
    res_out_tdisp->value("init");
    res_out_tdisp->box(FL_FLAT_BOX);
    res_out_tdisp->value("0");
    res_out_tdisp->textsize(18);
    //res_out_tdisp->set_visible_focus();
    res_out_tdisp->set_change_callback(output_changed_callback, nullptr);

    hex_out_disp = new Fl_Output(40, 40, 245, 20, "HEX");
    hex_out_disp->box(FL_FLAT_BOX);
    hex_out_disp->value("0");
    hex_out_disp->callback(num_type_callback, MODE_HEX);

    dec_out_disp = new Fl_Output(40, 60, 245, 20, "DEC");
    dec_out_disp->box(FL_FLAT_BOX);
    dec_out_disp->value("0");
    dec_out_disp->callback(num_type_callback, MODE_DEC);

    oct_out_disp = new Fl_Output(40, 80, 245, 20, "OCT");
    oct_out_disp->box(FL_FLAT_BOX);
    oct_out_disp->value("0");
    oct_out_disp->callback(num_type_callback, MODE_OCT);

    bin_out_disp = new Fl_Output(40, 100, 245, 20, "BIN");
    bin_out_disp->box(FL_FLAT_BOX);
    bin_out_disp->value("0");
    bin_out_disp->callback(num_type_callback, MODE_BIN);

    //new row
    inc_v_cnt(90);

    back_box = new Fl_Box(0, v_cnt-10, 285, 310);
    back_box->color(FL_GRAY);
    back_box->box(FL_FLAT_BOX);

    //numericals and ops
    op_lshift_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "<<");
    op_lshift_btn->type(FL_NORMAL_BUTTON);
    op_lshift_btn->box(FL_FLAT_BOX);
    op_lshift_btn->callback(op_callback, OP_LSHIFT);
    inc_h_cnt(h_inc_s);

    op_rshift_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, ">>");
    op_rshift_btn->type(FL_NORMAL_BUTTON);
    op_rshift_btn->box(FL_FLAT_BOX);
    op_rshift_btn->callback(op_callback, OP_RSHIFT);
    inc_h_cnt(h_inc_s);

    op_or_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "OR");
    op_or_btn->type(FL_NORMAL_BUTTON);
    op_or_btn->box(FL_FLAT_BOX);
    op_or_btn->callback(op_callback, OP_OR);
    inc_h_cnt(h_inc_s);

    op_xor_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "XOR");
    op_xor_btn->type(FL_NORMAL_BUTTON);
    op_xor_btn->box(FL_FLAT_BOX);
    op_xor_btn->callback(op_callback, OP_XOR);
    inc_h_cnt(h_inc_s);

    op_not_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "NOT");
    op_not_btn->type(FL_NORMAL_BUTTON);
    op_not_btn->box(FL_FLAT_BOX);
    op_not_btn->callback(op_callback, OP_NOT);
    inc_h_cnt(h_inc_s);

    op_and_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "AND");
    op_and_btn->type(FL_NORMAL_BUTTON);
    op_and_btn->box(FL_FLAT_BOX);
    op_and_btn->callback(op_callback, OP_AND);
    inc_h_cnt(h_inc_s);

    //new row
    inc_v_cnt(v_inc_s);

    empty_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "");
    empty_btn->type(FL_NORMAL_BUTTON);
    empty_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    empty_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "Mod");
    empty_btn->type(FL_NORMAL_BUTTON);
    empty_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    empty_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "CE");
    empty_btn->type(FL_NORMAL_BUTTON);
    empty_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    empty_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "C");
    empty_btn->type(FL_NORMAL_BUTTON);
    empty_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    empty_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "Del");
    empty_btn->type(FL_NORMAL_BUTTON);
    empty_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    op_div_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "/");
    op_div_btn->type(FL_NORMAL_BUTTON);
    op_div_btn->box(FL_FLAT_BOX);
    op_div_btn->callback(op_callback, OP_DIV);
    inc_h_cnt(h_inc_s);

    //new row
    inc_v_cnt(v_inc_s);

    numA_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "A");
    numA_btn->type(FL_NORMAL_BUTTON);
    numA_btn->box(FL_FLAT_BOX);
    numA_btn->callback(op_num_callback, 0xA);
    inc_h_cnt(h_inc_s);

    numB_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "B");
    numB_btn->type(FL_NORMAL_BUTTON);
    numB_btn->box(FL_FLAT_BOX);
    numB_btn->callback(op_num_callback, 0xB);
    inc_h_cnt(h_inc_s);

    num7_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "7");
    num7_btn->type(FL_NORMAL_BUTTON);
    num7_btn->box(FL_FLAT_BOX);
    num7_btn->callback(op_num_callback, 0x7);
    inc_h_cnt(h_inc_s);

    num8_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "8");
    num8_btn->type(FL_NORMAL_BUTTON);
    num8_btn->box(FL_FLAT_BOX);
    num8_btn->callback(op_num_callback, 0x8);
    inc_h_cnt(h_inc_s);

    num9_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "9");
    num9_btn->type(FL_NORMAL_BUTTON);
    num9_btn->box(FL_FLAT_BOX);
    num9_btn->callback(op_num_callback, 0x9);
    inc_h_cnt(h_inc_s);

    op_mult_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "*");
    op_mult_btn->type(FL_NORMAL_BUTTON);
    op_mult_btn->box(FL_FLAT_BOX);
    op_mult_btn->callback(op_callback, OP_MULT);
    inc_h_cnt(h_inc_s);

    //new row
    inc_v_cnt(v_inc_s);

    numC_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "C");
    numC_btn->type(FL_NORMAL_BUTTON);
    numC_btn->box(FL_FLAT_BOX);
    numC_btn->callback(op_num_callback, 0xC);
    inc_h_cnt(h_inc_s);

    numD_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "D");
    numD_btn->type(FL_NORMAL_BUTTON);
    numD_btn->box(FL_FLAT_BOX);
    numD_btn->callback(op_num_callback, 0xD);
    inc_h_cnt(h_inc_s);

    num4_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "4");
    num4_btn->type(FL_NORMAL_BUTTON);
    num4_btn->box(FL_FLAT_BOX);
    num4_btn->callback(op_num_callback, 0x4);
    inc_h_cnt(h_inc_s);

    num5_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "5");
    num5_btn->type(FL_NORMAL_BUTTON);
    num5_btn->box(FL_FLAT_BOX);
    num5_btn->callback(op_num_callback, 0x5);
    inc_h_cnt(h_inc_s);

    num6_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "6");
    num6_btn->type(FL_NORMAL_BUTTON);
    num6_btn->box(FL_FLAT_BOX);
    num6_btn->callback(op_num_callback, 0x6);
    inc_h_cnt(h_inc_s);

    op_minus_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "-");
    op_minus_btn->type(FL_NORMAL_BUTTON);
    op_minus_btn->box(FL_FLAT_BOX);
    op_minus_btn->callback(op_callback, OP_SUB);
    inc_h_cnt(h_inc_s);

    //new row
    inc_v_cnt(v_inc_s);

    numE_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "E");
    numE_btn->type(FL_NORMAL_BUTTON);
    numE_btn->box(FL_FLAT_BOX);
    numE_btn->callback(op_num_callback, 0xE);
    inc_h_cnt(h_inc_s);

    numF_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "F");
    numF_btn->type(FL_NORMAL_BUTTON);
    numF_btn->box(FL_FLAT_BOX);
    numF_btn->callback(op_num_callback, 0xF);
    inc_h_cnt(h_inc_s);

    num1_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "1");
    num1_btn->type(FL_NORMAL_BUTTON);
    num1_btn->box(FL_FLAT_BOX);
    num1_btn->callback(op_num_callback, 0x1);
    inc_h_cnt(h_inc_s);

    num2_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "2");
    num2_btn->type(FL_NORMAL_BUTTON);
    num2_btn->box(FL_FLAT_BOX);
    num2_btn->callback(op_num_callback, 0x2);
    inc_h_cnt(h_inc_s);

    num3_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "3");
    num3_btn->type(FL_NORMAL_BUTTON);
    num3_btn->box(FL_FLAT_BOX);
    num3_btn->callback(op_num_callback, 0x3);
    inc_h_cnt(h_inc_s);

    op_plus_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "+");
    op_plus_btn->type(FL_NORMAL_BUTTON);
    op_plus_btn->box(FL_FLAT_BOX);
    op_plus_btn->callback(op_callback, OP_ADD);
    inc_h_cnt(h_inc_s);

    //new row
    inc_v_cnt(v_inc_s);

    op_lbrace_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "(");
    op_lbrace_btn->type(FL_NORMAL_BUTTON);
    op_lbrace_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    op_rbrace_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, ")");
    op_rbrace_btn->type(FL_NORMAL_BUTTON);
    op_rbrace_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    op_neg_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "+/-");
    op_neg_btn->type(FL_NORMAL_BUTTON);
    op_neg_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    num0_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "0");
    num0_btn->type(FL_NORMAL_BUTTON);
    num0_btn->box(FL_FLAT_BOX);
    num0_btn->callback(op_num_callback, 0x0);
    inc_h_cnt(h_inc_s);

    op_dec_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, ".");
    op_dec_btn->type(FL_NORMAL_BUTTON);
    op_dec_btn->box(FL_FLAT_BOX);
    inc_h_cnt(h_inc_s);

    op_equal_btn = new Fl_Button(h_cnt, v_cnt, 40, 40, "=");
    op_equal_btn->type(FL_NORMAL_BUTTON);
    op_equal_btn->box(FL_FLAT_BOX);
    op_equal_btn->callback(op_callback, OP_EQUAL);
    inc_h_cnt(h_inc_s);

    //new row
    inc_v_cnt(v_inc_s);

    //set default mode to DEC
    dec_out_disp->do_callback();

    window->end();
    window->show(argc, argv);
    return Fl::run();
}
