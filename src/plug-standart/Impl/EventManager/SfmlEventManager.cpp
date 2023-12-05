#include "Impl/EventManager/SfmlEventManager.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cassert>

using namespace plug;

static MouseButton getMouseKey(sf::Mouse::Button sf_button);

static KeyCode getKeyCode(sf::Keyboard::Key key);

void SfmlEventManager::sendEvents(Widget *widget) {
  EHC context{.stack = m_stack, .stopped = false, .overlapped = false};
  widget->onEvent(makeTickEvent(), context);

  sf::Event sf_event;
  while (m_window.isOpen() && m_window.pollEvent(sf_event)) {
    context.stopped = false;
    context.overlapped = false;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch-enum"
    switch (sf_event.type) {
    case sf::Event::Closed:
      m_window.close();
      break;
    case sf::Event::MouseMoved:
      widget->onEvent(convertMove(sf_event), context);
      break;
    case sf::Event::MouseButtonPressed:
      widget->onEvent(convertMousePressed(sf_event), context);
      break;
    case sf::Event::MouseButtonReleased:
      widget->onEvent(convertMouseReleased(sf_event), context);
      break;
    case sf::Event::KeyPressed:
      widget->onEvent(convertKeyPressed(sf_event), context);
      m_shiftPressed = sf_event.key.shift;
      m_ctrlPressed = sf_event.key.control;
      m_altPressed = sf_event.key.alt;
      break;
    case sf::Event::KeyReleased:
      widget->onEvent(convertKeyReleased(sf_event), context);
      m_shiftPressed = sf_event.key.shift;
      m_ctrlPressed = sf_event.key.control;
      m_altPressed = sf_event.key.alt;
      break;
    default:
      break;
    }
#pragma clang diagnostic pop
  }
}

MouseMoveEvent SfmlEventManager::convertMove(const sf::Event &sf_event) const {
  assert(sf_event.type == sf::Event::MouseMoved);
  const sf::Event::MouseMoveEvent &move_event = sf_event.mouseMove;

  // clang-format off
  return {
    Vec2d{move_event.x, move_event.y},
    m_shiftPressed, m_ctrlPressed, m_altPressed
  };
  // clang-format on
}

MousePressedEvent
SfmlEventManager::convertMousePressed(const sf::Event &sf_event) const {
  assert(sf_event.type == sf::Event::MouseButtonPressed);
  const sf::Event::MouseButtonEvent &mouse_event = sf_event.mouseButton;

  // clang-format off
  return {
    getMouseKey(mouse_event.button),
    Vec2d{mouse_event.x, mouse_event.y},
    m_shiftPressed, m_ctrlPressed, m_altPressed
  };
  // clang-format on
}

MouseReleasedEvent
SfmlEventManager::convertMouseReleased(const sf::Event &sf_event) const {
  assert(sf_event.type == sf::Event::MouseButtonReleased);
  const sf::Event::MouseButtonEvent &mouse_event = sf_event.mouseButton;

  // clang-format off
  return {
    getMouseKey(mouse_event.button),
    Vec2d{mouse_event.x, mouse_event.y},
    m_shiftPressed, m_ctrlPressed, m_altPressed
  };
  // clang-format on
}

KeyboardPressedEvent
SfmlEventManager::convertKeyPressed(const sf::Event &sf_event) const {
  assert(sf_event.type == sf::Event::KeyPressed);
  const sf::Event::KeyEvent &key_event = sf_event.key;

  // clang-format off
  return {
    getKeyCode(key_event.code),
    m_shiftPressed, m_ctrlPressed, m_altPressed
  };
  // clang-format on
}

KeyboardReleasedEvent
SfmlEventManager::convertKeyReleased(const sf::Event &sf_event) const {
  assert(sf_event.type == sf::Event::KeyReleased);
  const sf::Event::KeyEvent &key_event = sf_event.key;

  // clang-format off
  return {
    getKeyCode(key_event.code),
    m_shiftPressed, m_ctrlPressed, m_altPressed
  };
  // clang-format on
}

TickEvent SfmlEventManager::makeTickEvent(void) {
  double seconds = m_clock.restart().asSeconds();
  return TickEvent(seconds);
}

static inline plug::MouseButton getMouseKey(sf::Mouse::Button sf_button) {
  using sB = sf::Mouse::Button;
  using pB = plug::MouseButton;

  switch (sf_button) {
  case sB::Left:
    return pB::Left;
  case sB::Right:
    return pB::Right;
  case sB::Middle:
    return pB::Middle;

  case sB::XButton1:
    return pB::XButton1;
  case sB::XButton2:
    return pB::XButton2;
  case sB::ButtonCount:
  default:
    return pB::ButtonCount;
  }
}

static plug::KeyCode getKeyCode(sf::Keyboard::Key key) {
#define CONVERT_KEY(key)                                                       \
  case sf::Keyboard::key:                                                      \
    return plug::KeyCode::key
  switch (key) {
    CONVERT_KEY(A);
    CONVERT_KEY(B);
    CONVERT_KEY(C);
    CONVERT_KEY(D);
    CONVERT_KEY(E);
    CONVERT_KEY(F);
    CONVERT_KEY(G);
    CONVERT_KEY(H);
    CONVERT_KEY(I);
    CONVERT_KEY(J);
    CONVERT_KEY(K);
    CONVERT_KEY(L);
    CONVERT_KEY(M);
    CONVERT_KEY(N);
    CONVERT_KEY(O);
    CONVERT_KEY(P);
    CONVERT_KEY(Q);
    CONVERT_KEY(R);
    CONVERT_KEY(S);
    CONVERT_KEY(T);
    CONVERT_KEY(U);
    CONVERT_KEY(V);
    CONVERT_KEY(W);
    CONVERT_KEY(X);
    CONVERT_KEY(Y);
    CONVERT_KEY(Z);
    CONVERT_KEY(Num0);
    CONVERT_KEY(Num1);
    CONVERT_KEY(Num2);
    CONVERT_KEY(Num3);
    CONVERT_KEY(Num4);
    CONVERT_KEY(Num5);
    CONVERT_KEY(Num6);
    CONVERT_KEY(Num7);
    CONVERT_KEY(Num8);
    CONVERT_KEY(Num9);
    CONVERT_KEY(Escape);
    CONVERT_KEY(LControl);
    CONVERT_KEY(LShift);
    CONVERT_KEY(LAlt);
    CONVERT_KEY(LSystem);
    CONVERT_KEY(RControl);
    CONVERT_KEY(RShift);
    CONVERT_KEY(RAlt);
    CONVERT_KEY(RSystem);
    CONVERT_KEY(Menu);
    CONVERT_KEY(LBracket);
    CONVERT_KEY(RBracket);
    CONVERT_KEY(Semicolon);
    CONVERT_KEY(Comma);
    CONVERT_KEY(Period);
    CONVERT_KEY(Quote);
    CONVERT_KEY(Slash);
    CONVERT_KEY(Backslash);
    CONVERT_KEY(Tilde);
    CONVERT_KEY(Equal);
    CONVERT_KEY(Hyphen);
    CONVERT_KEY(Space);
    CONVERT_KEY(Enter);
    CONVERT_KEY(Backspace);
    CONVERT_KEY(Tab);
    CONVERT_KEY(PageUp);
    CONVERT_KEY(PageDown);
    CONVERT_KEY(End);
    CONVERT_KEY(Home);
    CONVERT_KEY(Insert);
    CONVERT_KEY(Delete);
    CONVERT_KEY(Add);
    CONVERT_KEY(Subtract);
    CONVERT_KEY(Multiply);
    CONVERT_KEY(Divide);
    CONVERT_KEY(Left);
    CONVERT_KEY(Right);
    CONVERT_KEY(Up);
    CONVERT_KEY(Down);
    CONVERT_KEY(Numpad0);
    CONVERT_KEY(Numpad1);
    CONVERT_KEY(Numpad2);
    CONVERT_KEY(Numpad3);
    CONVERT_KEY(Numpad4);
    CONVERT_KEY(Numpad5);
    CONVERT_KEY(Numpad6);
    CONVERT_KEY(Numpad7);
    CONVERT_KEY(Numpad8);
    CONVERT_KEY(Numpad9);
    CONVERT_KEY(F1);
    CONVERT_KEY(F2);
    CONVERT_KEY(F3);
    CONVERT_KEY(F4);
    CONVERT_KEY(F5);
    CONVERT_KEY(F6);
    CONVERT_KEY(F7);
    CONVERT_KEY(F8);
    CONVERT_KEY(F9);
    CONVERT_KEY(F10);
    CONVERT_KEY(F11);
    CONVERT_KEY(F12);
    CONVERT_KEY(F13);
    CONVERT_KEY(F14);
    CONVERT_KEY(F15);
    CONVERT_KEY(Pause);

    CONVERT_KEY(KeyCount);
    CONVERT_KEY(Unknown);

  default:
    return plug::KeyCode::Unknown;
  }
#undef CONVERT_KEY
}
