#ifndef SUBJECT_03_HPP_
#define SUBJECT_03_HPP_
#include <iostream>
#include <cstring>
#include <initializer_list>
using std::initializer_list;
using std::strcpy, std::strncpy, std::strlen, std::cout, std::endl;

#include "workermi.h"

namespace subject03
{
  template <typename T, int max_queue_size>
  class QueueTp
  {
  private:
    T m_queue[max_queue_size + 1];
    int m_front, m_rear;
    int m_queue_size;

  public:
    QueueTp() { m_front = m_rear = m_queue_size = 0; }
    QueueTp(initializer_list<T> &list);
    QueueTp(const QueueTp &queue_tp) = delete;
    QueueTp(QueueTp &&queue_tp) = delete;
    ~QueueTp() = default;

    QueueTp &operator=(const QueueTp &queue_tp) = delete;
    QueueTp &operator=(QueueTp &&queue_tp) = delete;

    bool EnQueue(const T &data);
    bool Dequeue(T &data);
    T &GetFront() { return m_queue[m_front]; }
    int QueueSize() { return (m_rear + max_queue_size + 1 - m_front) % (max_queue_size + 1); }
    void Clear() { m_front = m_rear = m_queue_size = 0; }
    bool Isfull() { return (m_rear + max_queue_size + 2) % (max_queue_size + 1) == m_front; }
    bool IsEmpty() { return m_front == m_rear; }
  };

  template <typename T, int max_queue_size>
  QueueTp<T, max_queue_size>::QueueTp(initializer_list<T> &list)
  {
    if (list.size() > max_queue_size)
      m_queue_size = m_rear = max_queue_size;
    else
      m_queue_size = m_rear = list.size();

    m_front = 0;

    for (int i = 0; i < m_queue_size; i++)
      m_queue[i] = *(list.begin() + i);
  }

  template <typename T, int max_queue_size>
  bool QueueTp<T, max_queue_size>::EnQueue(const T &data)
  {
    if (Isfull())
      return false;
    else
    {
      m_queue[m_rear] = data;
      m_rear = (m_rear + 1) % (max_queue_size + 1);
      m_queue_size++;
      return true;
    }
  }

  template <typename T, int max_queue_size>
  bool QueueTp<T, max_queue_size>::Dequeue(T &data)
  {
    if (IsEmpty())
      return false;
    else
    {
      data = m_queue[m_front];
      m_front = (m_front + 1) % (max_queue_size + 1);
      m_queue_size--;
      return true;
    }
  }

  using WorkerQueue = QueueTp<Worker *, 5>;

}
#endif
