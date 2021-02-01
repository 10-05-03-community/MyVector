#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <iostream>

template<typename Type>
class MyVector {

  public:
    // стандартный конструктор
    MyVector();

    // конструктор копирования
    MyVector(const MyVector & other);

    // оператор копирующего присваивания
    MyVector & operator= (const MyVector & other);

    // конструктор перемещения
    // пока не надо
    // MyVector(MyVector && other);

    // оператор присваивания перемещением
    // пока не надо
    // MyVector operator= (MyVector && other);

    // деструктор
    ~MyVector();

    // добавить элемент в конец вектора
    void push_back(const Type & element);

    // удалить элемент из конца вектора
    void pop_back();

    // добавить в вектор count элементов со значением value
    void assign(std::size_t count, const Type & value);

    // вовзрат ссылки на последний элемент в векторе
    const Type & back() const;

    // вовзрат ссылки на первый элемент в векторе
    const Type & front() const;

    // вовзращает текущую вместимость вектора
    std::size_t capacity() const;

    // возвращает текущий размер вектора
    std::size_t size() const;

    // вовзращает true, если вектор пустой, иначе - false
    bool empty() const;

    // очищает вектор
    void clear();

    // выделяет память для хранения как минимум size элементов типа Type, не инициализируя
    void reserve(std::size_t size);

    // делает размер вектора как минимум count и инициализирует эти элементы стандартным значением
    void resize(std::size_t count);

    // если неиспользуемой памяти слишком много, то сокращает её размер
    void shrink_to_fit();

    // вовзращает ссылку на элемент в позиции index
    Type & at(std::size_t index);

    // возвращает константную ссылку на элемент в позиции index
    const Type & at(std::size_t index) const;

    // вовзращает ссылку на элемент в позиции index
    Type & operator[](std::size_t index);

    // возвращает константную ссылку на элемент в позиции index
    const Type & operator[](std::size_t index) const;

    // вставка в конец стразу нескольких элементов
    // пока не надо
    // template <class Args>
    // void emplace_back(Args && args);

    // функция вывода в консоль
    template<typename T>
    friend std::ostream & operator<<(std::ostream & out, const MyVector<T> v);

  private:

    // указатель на массив с данными
    Type* array_;

    // число элементов в массиве
    std::size_t count_;

    // вместимость массива
    std::size_t capacity_;

};

//***************************************************************************//

template<typename Type>
MyVector<Type>::MyVector()
{
    array_ = nullptr;
    count_ = 0;
    capacity_ = 0;
}

template<typename Type>
MyVector<Type>::MyVector(const MyVector & other)
{

}

template<typename Type>
MyVector<Type> & MyVector<Type>::operator=(const MyVector &other)
{
    return *this;
}

template<typename Type>
MyVector<Type>::~MyVector()
{
    if (array_ != nullptr) {
        delete[] array_;
    }
}

template<typename Type>
void MyVector<Type>::push_back(const Type & element)
{

}

template<typename Type>
void MyVector<Type>::pop_back()
{

}

template<typename Type>
void MyVector<Type>::assign(std::size_t count, const Type & value)
{

}

template<typename Type>
const Type & MyVector<Type>::back() const
{
    return *array_;
}

template<typename Type>
const Type & MyVector<Type>::front() const
{
    return *array_;
}

template<typename Type>
std::size_t MyVector<Type>::capacity() const
{
    return 0;
}

template<typename Type>
std::size_t MyVector<Type>::size() const
{
    return 0;
}

template<typename Type>
bool MyVector<Type>::empty() const
{
    return true;
}

template<typename Type>
void MyVector<Type>::clear()
{

}

template<typename Type>
void MyVector<Type>::reserve(std::size_t size)
{

}

template<typename Type>
void MyVector<Type>::resize(std::size_t count)
{

}

template<typename Type>
void MyVector<Type>::shrink_to_fit()
{

}

template<typename Type>
Type & MyVector<Type>::at(std::size_t index)
{
    return *array_;
}

template<typename Type>
const Type & MyVector<Type>::at(std::size_t index) const
{
    return *array_;
}

template<typename Type>
Type & MyVector<Type>::operator[](std::size_t index)
{
    return *array_;
}

template<typename Type>
const Type & MyVector<Type>::operator[](std::size_t index) const
{
    return *array_;
}

template<typename T>
std::ostream & operator<<(std::ostream & out, const MyVector<T> v) {
    return out;
}

//***************************************************************************//

#endif // MYVECTOR_HPP
