/**
 * @file TransformStack.h
 * @author MeerkatBoss (solodovnikov.ia@phystech.edu)
 *
 * @brief
 *
 * @version 0.1
 * @date 2023-11-22
 *
 * @copyright Copyright MeerkatBoss (c) 2023
 */
#ifndef __IMPL_TRANSFORM_STACK_H
#define __IMPL_TRANSFORM_STACK_H

#include "Plug/Math/TransformStack.h"

class TransformStack : public plug::TransformStack {
public:
  TransformStack(void)
      : m_stack(new plug::Transform[DefaultCapacity]), m_stackSize(1),
        m_stackCapacity(DefaultCapacity) {
    m_stack[0] = plug::Transform();
  }

  virtual ~TransformStack(void) override { delete[] m_stack; }

  virtual void enter(const plug::Transform &transform) override;

  virtual void leave(void) override;

  virtual plug::Transform top(void) const override;

  virtual plug::Vec2d apply(const plug::Vec2d &vec) const override;

  virtual plug::Vec2d restore(const plug::Vec2d &vec) const override;

private:
  void push(const plug::Transform &transform);

  void pop(void);

  void grow(void);

  static constexpr size_t DefaultCapacity = 16;

  plug::Transform *m_stack;
  size_t m_stackSize;
  size_t m_stackCapacity;
};

#endif /* TransformStack.h */
