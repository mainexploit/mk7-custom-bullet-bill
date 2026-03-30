#include <base/caption.hpp>

#include <base/sead/safe_string.hpp>
#include <base/pointers.hpp>

#include <wchar.h>

UI::ControlSight::ElementHandle::ElementHandle() { m_element = nullptr; }

namespace base
{
    void    caption::init(Sequence::BasePage *base_page)
    {
        auto initializer = base_page->m_control_initializer;
        auto director = initializer->m_control_director;
        auto safe_str = _sead::safe_string("caption");

        base_page->m_set_item_to_all_manipulators = true;

        auto create_arg = g_pointers->m_UI_VisualControl_CreateArg_sub_object(g_pointers->m_operator_new(sizeof(UI::VisualControl::CreateArg)));
        
        *reinterpret_cast<void **>(create_arg) = g_pointers->m_UI_VisualControl_CreateArg_vtbl;

        g_pointers->m_UI_ControlAnimator_AnimationDefine_sub_object(&create_arg->m_animation_define);

        *reinterpret_cast<void **>(&create_arg->m_animation_define) = g_pointers->m_UI_VisualControl_CreateArg_AnimationDefine_vtbl;

        auto caption = reinterpret_cast<UI::MenuCaption *>(g_pointers->m_UI_BaseMenuViewControl_ctor(g_pointers->m_operator_new(sizeof(UI::MenuCaption))));

        *reinterpret_cast<void **>(caption) = g_pointers->m_UI_BaseMenuViewControl_vtbl;

        caption->initNode(director);

        g_pointers->m_Util_TIndLinkList_UI_Control_append(&director->m_it, &caption->m_control_list_node);

        initializer->m_control = caption;

        g_pointers->m_UI_ControlInitializer_initCreateArg(initializer, create_arg, safe_str, safe_str);

        initializer->m_control_create_arg = create_arg;

        g_pointers->m_UI_ControlInitializer_endSetupControl(initializer, create_arg);

        base_page->m_set_item_to_all_manipulators = false;

        base_page->m_controls_outside_manipulator_array.pushBack(caption);

        init(caption);
    }

    void    caption::init(UI::MenuCaption *caption)
    {
        if (m_instance = caption)
        {
            realloc_str_buf();

            hide_background();

            g_pointers->m_UI_MenuCaption_animKeep(m_instance);
        }
    }

    void    caption::realloc_str_buf()
    {
        if (m_instance)
        {
            if (auto text_box = get_text_box())
            {
                text_box->FreeStringBuffer();

                text_box->AllocStringBuffer((std::size(m_wbuf) >> 1) - 1);
            }
        }
    }

    void    caption::printf(f32 x, f32 y, const wchar_t *fmt, ...)
    {
        if (m_instance)
        {
            set_position(x, y);

            va_list args;
            va_start(args, fmt);
            UI::MessageString message = fmt_message(m_wbuf, std::size(m_wbuf), fmt, args);
            va_end(args);

            set_message(message);
        }
    }

    void    caption::printf(const wchar_t *fmt, ...)
    {
        if (m_instance)
        {
            va_list args;
            va_start(args, fmt);
            UI::MessageString message = fmt_message(m_wbuf, std::size(m_wbuf), fmt, args);
            va_end(args);

            set_message(message);
        }
    }

    void    caption::animate(Animation anim)
    {
        if (m_instance && m_last_anim != anim)
        {
            switch (anim)
            {
                case Animation::Out:
                    g_pointers->m_UI_MenuCaption_animOut(m_instance);
                break;

                case Animation::In:
                    g_pointers->m_UI_MenuCaption_animIn(m_instance);
                break;
            }

            m_last_anim = anim;
        }
    }

    void    caption::set_visible(bool visible)
    {
        if (m_instance)
            if (auto text_box = get_text_box())
                text_box->m_flag = visible;
    }

    bool    caption::is_visible()
    {
        if (m_instance)
            if (auto text_box = get_text_box())
                return static_cast<bool>(text_box->m_flag);
        
        return false;
    }
    
    void    caption::hide_background()
    {
        if (m_instance)
        {
            UI::ControlSight::ElementHandle pane_handle;

            if (pane_handle.m_element = get_background())
            {
                g_pointers->m_UI_BaseFastControl_setPosX(m_instance, pane_handle, 400.f); // push the background out of screen
                g_pointers->m_UI_BaseFastControl_setPosY(m_instance, pane_handle, -105.f); // re-align misaligned captions
            }
        }
    }

    void    caption::set_message(const UI::MessageString &message)
    {
        if (m_instance)
            m_instance->m_control_sight->replaceMessageImpl(reinterpret_cast<u32>(m_instance->m_elements[0]), message, nullptr, nullptr);  
    }

    void    caption::set_message(s32 message_id)
    {
        UI::MessageString message;

        UI::MessageDataList::getMessage(message, &m_instance->m_message_data_list, message_id);

        set_message(message);
    }

    void    caption::set_color(const Color8 color, GradientLayer color_location = GradientLayer::All)
    {
        if (m_instance)
        {
            if (auto text_box = get_text_box())
            {
                if (color_location == GradientLayer::All)
                {
                    text_box->mTextColors[std::to_underlying(GradientLayer::Top)] = color;
                    text_box->mTextColors[std::to_underlying(GradientLayer::Bottom)] = color;

                    return;
                }
                
                text_box->mTextColors[std::to_underlying(color_location)] = color;
            }
        }
    }

    void    caption::set_alignment(Alignment alignment)
    {
        if (m_instance)
            if (auto text_box = get_text_box())
                text_box->mTextPosition = std::to_underlying(alignment);
    }

    void    caption::set_position(f32 x, f32 y)
    {
        if (m_instance)
        {
            UI::ControlSight::ElementHandle text_box_handle;

            if (text_box_handle.m_element = get_text_box())
            {
                x -= 400.f; // substract -400.f due to background shift

                g_pointers->m_UI_BaseFastControl_setPosX(m_instance, text_box_handle, x);
                g_pointers->m_UI_BaseFastControl_setPosY(m_instance, text_box_handle, y);
            }
        }
    }

    void    caption::set_outline(Outline color = Outline::Black)
    {
        if (m_instance)
            if (auto text_box = get_text_box())
                text_box->mOutlineColor = std::to_underlying(color);
    }

    void    caption::set_screen(Screen screen)
    {
        if (m_instance)
            m_instance->m_draw_screen_flag |= std::to_underlying(screen);
    }

    void    caption::set_size(f32 size)
    {
        if (m_instance)
        {
            if (auto text_box = get_text_box())
            {
                text_box->mFontSize.width = size;
                text_box->mFontSize.height = size * 1.18181812763f;
            }
        }  
    }

    void    caption::set_line_space(f32 line_space)
    {
        if (m_instance)
            if (auto text_box = get_text_box())
                text_box->mLineSpace = line_space;
    }

    void    caption::set_char_space(f32 char_space)
    {
        if (m_instance)
            if (auto text_box = get_text_box())
                text_box->mCharSpace = char_space;
    }

    float   caption::get_font_width()
    {
        if (m_instance)
            if (auto text_box = get_text_box())
                return text_box->mFontSize.width;
        
        return 0.f;
    }

    UI::MessageString   caption::fmt_message(wchar_t *dest_buf, u16 dest_chars, const wchar_t *fmt, va_list args)
    {
        if (!dest_buf || !dest_chars)
            return UI::MessageString(nullptr);

        s32 written = g_pointers->m_c89vswprintf(dest_buf, dest_chars, fmt, args);

        if (written < 0)
            dest_buf[0] = L'\0';
        
        else if (static_cast<u16>(written) >= dest_chars)
            dest_buf[dest_chars - 1] = L'\0';

        return UI::MessageString(reinterpret_cast<char16 *>(dest_buf));
    }

    nw::lyt::TextBox    *caption::get_text_box()
    {
        if (m_instance)
            if (auto m_element = m_instance->m_control_sight->getElementHandle("T_caption_00", UI::ControlSight::EElementType::ELEMENT_TYPE_TEXTBOX))
                return static_cast<nw::lyt::TextBox *>(m_element);
        
        return nullptr;
    }

    nw::lyt::Pane   *caption::get_background()
    {
        if (m_instance)
            if (auto m_element = m_instance->m_control_sight->getElementHandle("R_center", UI::ControlSight::EElementType::ELEMENT_TYPE_PANE))
                return static_cast<nw::lyt::Pane *>(m_element);
        
        return nullptr;
    }
}