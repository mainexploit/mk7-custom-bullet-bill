#include <UI/MenuCaption.hpp>

#include <Sequence/BaseMenuPage.hpp>
#include <Sequence/BaseRacePage.hpp>

namespace base
{
    enum class Animation
    {
        Out,
        In
    };
    
    struct Color8 : nw::ut::Color8 { using nw::ut::Color8::Color8; };

    enum class GradientLayer : s8
    {
        Top = nw::lyt::TEXTCOLOR_TOP,
        Bottom = nw::lyt::TEXTCOLOR_BOTTOM,
        All = nw::lyt::TEXTCOLOR_MAX
    };

    enum class Alignment : s8
    {
        BottomLeft = nw::lyt::ALIGN_BOTTOM_LEFT,
        BottomCenter = nw::lyt::ALIGN_BOTTOM_CENTER,
        BottomRight = nw::lyt::ALIGN_BOTTOM_RIGHT,
        MiddleLeft = nw::lyt::ALIGN_CENTER_LEFT,
        MiddleCenter = nw::lyt::ALIGN_CENTER_CENTER,
        MiddleRight = nw::lyt::ALIGN_CENTER_RIGHT,
        TopLeft = nw::lyt::ALIGN_TOP_LEFT,
        TopCenter = nw::lyt::ALIGN_TOP_CENTER,
        TopRight = nw::lyt::ALIGN_TOP_RIGHT,
    };

    enum class Outline : s8
    {
        Gray = nw::lyt::TEXT_OUTLINE_GRAY,
        Black = nw::lyt::TEXT_OUTLINE_BLACK,
        None = nw::lyt::TEXT_OUTLINE_NONE
    };

    enum class Screen : s32
    {
        Top = UI::Control::ControlDrawScreenFlag::DRAW_ON_TOP_SCREEN,
        Bottom = UI::Control::ControlDrawScreenFlag::DRAW_ON_BOTTOM_SCREEN
    };

    class caption
    {
    public:
        caption() {};
        ~caption() = default;
        
        void init(Sequence::BasePage *);
        void init(UI::MenuCaption *);

        void realloc_str_buf();

        void printf(f32, f32, const wchar_t *, ...);
        void printf(const wchar_t *, ...);

        void animate(Animation);

        void set_visible(bool);
        bool is_visible();

        void hide_background();

        void set_message(const UI::MessageString &);
        void set_message(s32);

        void set_color(const Color8, GradientLayer);
        void set_alignment(Alignment);
        void set_position(f32, f32);
        void set_outline(Outline);
        void set_screen(Screen);
        void set_size(f32);

        void set_line_space(f32);
        void set_char_space(f32);

    private:
        UI::MenuCaption *m_instance;
        Animation m_last_anim;

        nw::lyt::TextBox *get_text_box();
        nw::lyt::Pane *get_background();

        UI::MessageString fmt_message(wchar_t *, u16, const wchar_t *, va_list);
        wchar_t m_wbuf[1024];
    };
}