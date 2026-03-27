#include <UI/MenuCaption.hpp>

#include <Sequence/BaseRacePage.hpp>

namespace base
{
    class caption
    {
    public:
        caption() {};
        ~caption() = default;

        void init(Sequence::BasePage *);
        void init(UI::MenuCaption *);

        void hide_background();
        void realloc_str_buf();

        void printf(f32, f32, const wchar_t *, ...);

        void set_message(const UI::MessageString &);
        void set_message(s32);

        void set_color(const nw::ut::Color8, s32);
        void set_outline_color(u8);

        void set_position(f32, f32);
        void set_size(f32, f32);

        void set_text_alignment(u8);
        void set_line_space(f32);
        void set_char_space(f32);
        
        enum class Screen
        {
            TOP,
            BOTTOM
        };

        void set_screen(Screen);

    private:
        UI::MenuCaption *m_instance;

        nw::lyt::TextBox *get_text_box();
        UI::MessageString fmt_message(wchar_t *, u16, const wchar_t *, va_list);
        wchar_t m_wbuf[1024];
    };
}