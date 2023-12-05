#include <cassert>

#include "Impl/TransformStack.h"

void TransformStack::enter(const plug::Transform &transform) {
  push(transform.combine(top()));
}

void TransformStack::leave(void) {
  assert(m_stackSize >= 1 && "TransformStack cannot be empty");
  pop();
}

plug::Transform TransformStack::top(void) const {
  return m_stack[m_stackSize - 1];
}

plug::Vec2d TransformStack::apply(const plug::Vec2d &vec) const {
  return top().apply(vec);
}

plug::Vec2d TransformStack::restore(const plug::Vec2d &vec) const {
  return top().restore(vec);
}

void TransformStack::push(const plug::Transform &transform) {
  if (m_stackSize == m_stackCapacity) {
    grow();
  }

  m_stack[m_stackSize] = transform;
  ++m_stackSize;
}

void TransformStack::pop(void) {
  m_stack[m_stackSize] = plug::Transform();
  --m_stackSize;
}

void TransformStack::grow(void) {
  const size_t new_capacity = 2 * m_stackCapacity;
  plug::Transform *new_stack = new plug::Transform[new_capacity];
  assert(new_stack && "Failed to allocate memory for stack");

  for (size_t i = 0; i < m_stackSize; ++i) {
    new_stack[i] = m_stack[i];
  }

  m_stack = new_stack;
  m_stackCapacity = new_capacity;
}
