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

    // вспомогательная функция для буферного массива
    void buf(const Type & element);

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
//стандартный конструктор
template<typename Type>
MyVector<Type>::MyVector() {
    array_ = nullptr;
    count_ = 0;
    capacity_ = 0;
}

//конструктор копирования
template<typename Type>
MyVector<Type>::MyVector(const MyVector & other) {

    this->count_ = other.count_; //получаем текущую заполненность

    if (this->capacity_ != 0) {
        this->array_ = new Type[other.capacity_]; //выделяем память под массив с вместимомтью копируемом
            //заполнение нового массива
        for (size_t i = 0; i < other.count_; i++) {
            this->array_[i] = other.array_[i];
        }
    } else MyVector();
}

//оператор копирующего присваивания
template<typename Type>
MyVector<Type> & MyVector<Type>::operator=(const MyVector &other) {
    //закомментировал, т.к. выдает ошибку
    if (this != &other) {
        if (this->capacity_ > 0) {
            delete[] this->array_;
        }

        this->count_ = other.count_; //получаем текущую заполненность
        this->capacity_ = other.capacity_; //получаем текущую вместимость

        if (this->capacity_ != 0) {
            this->array_ = new Type[other.capacity_]; //выделяем память под массив с вместимомтью копируемом
            //заполнение нового массива
            for (size_t i = 0; i < other.count_; i++) {
                this->array_[i] = other.array_[i];
            }
        } else MyVector();
    }
    return *this;
}

//деструктор
template<typename Type>
MyVector<Type>::~MyVector() {
    if (array_ != nullptr) {
        delete[] array_;
    }
}

// вспомогательная функция для буферного массива
template<typename Type>
void MyVector<Type>::buf(const Type & element) {
    //выделяем память под буферный массив
    Type *tmp_mas = new Type[capacity_];

    //копируем в буферный массив элементы из текущего массива
    for (size_t i = 0; i < count_; i++) {
        tmp_mas[i] = array_[i];
    }

    //искусственно добавляем в буферный массив новый элемент
    tmp_mas[count_] = element;
    count_++;

    //очищаем память основного массива
    if (array_ != nullptr) {
        delete[] array_;
    }

    //копируем буферный массив в новый основной
    array_ = tmp_mas;
}

//добавление элемента в вектор
template<typename Type>
void MyVector<Type>::push_back(const Type & element) {
    if (capacity_ == 0) {
        capacity_++;
    }
    if (count_ == capacity_) {
        //увеличиваем вместимость массива
        capacity_ *= 2;
        buf(element);
    } else if (count_ < capacity_) {
        buf(element);
    }
}

//удаление элемента из вектора
template<typename Type>
void MyVector<Type>::pop_back() {
    this->count_ -= 1;
}

//добавление в вектор count элементов со значением value
template<typename Type>
void MyVector<Type>::assign(std::size_t count, const Type & value) {
    if (capacity_ == 0) {
        capacity_++;
    }

    //очищаем память основного массива
    if (array_ != nullptr) {
        delete[] array_;
    }

    while (capacity_ < count) {
        capacity_ *= 2;
    }

    count_ = count;

    array_ = new Type [capacity_];

    for (size_t i = 0; i < count_; i++) {
        array_[i] = value;
    }
}

//вовзрат ссылки на последний элемент в векторе
template<typename Type>
const Type & MyVector<Type>::back() const {
    return array_[count_ - 1];
}

//вовзрат ссылки на первый элемент в векторе
template<typename Type>
const Type & MyVector<Type>::front() const {
    return array_[0];
}

//вовзращает текущую вместимость вектора
template<typename Type>
std::size_t MyVector<Type>::capacity() const {
    return capacity_;
}

//возвращает текущий размер вектора
template<typename Type>
std::size_t MyVector<Type>::size() const {
    return count_;
}

//вовзращает true, если вектор пустой, иначе - false
template<typename Type>
bool MyVector<Type>::empty() const {
    if (count_ > 0){
        return false;
    } else {
        return true;
    }
}

//очищает вектор
template<typename Type>
void MyVector<Type>::clear() {
    //очищаем память массива
    if (array_ != nullptr) {
        delete[] array_;
    }
    //возвращаяем массив в исходное состояние
    array_ = nullptr;
    count_ = 0;
    capacity_ = 0;
}

//выделяет память для хранения как минимум capacity_ элементов типа Type, не инициализируя
template<typename Type>
void MyVector<Type>::reserve(std::size_t size) {
    if (size > capacity_) {

        if (capacity_ == 0) {
            capacity_++;
        }

        while (capacity_ < size) {
            capacity_ *= 2;
        }

        Type *tmp_mas = new Type[capacity_];

        //копируем в буферный массив элементы из текущего массива
        for (size_t i = 0; i < count_; i++) {
            tmp_mas[i] = array_[i];
        }

        //очищаем память основного массива
        if (array_ != nullptr) {
            delete[] array_;
        }

        //копируем буферный массив в новый основной
        array_ = tmp_mas;
    }
}

//делает размер вектора как минимум count и инициализирует эти элементы стандартным значением
template<typename Type>
void MyVector<Type>::resize(std::size_t count) {

    if (count < capacity_) {
        capacity_ = count;
        for (size_t i = count_; i < count; i++) {
            array_[i] = {0};
        }
        count_ = count;
    } else if (count > capacity_) {

        if (capacity_ == 0) {
            capacity_++;
        }

        while (capacity_ < count) {
            capacity_ *= 2;
        }

        //выделяем память под буферный массив
        Type *tmp_mas = new Type[capacity_];

        //копируем в буферный массив элементы из текущего массива
        for (size_t i = 0; i < count_; i++) {
            tmp_mas[i] = array_[i];
        }

        for (size_t i = count_; i < count; i++) {
            tmp_mas[i] = {0};
        }

        count_ = count;

        //очищаем память основного массива
        if (array_ != nullptr) {
            delete[] array_;
        }

        //копируем буферный массив в новый основной
        array_ = tmp_mas;
    }

}


//если неиспользуемой памяти слишком много, то сокращает её размер
template<typename Type>
void MyVector<Type>::shrink_to_fit() {
    if (count_ == 0) {
        return;
    }

    if (count_ != capacity_) {

        capacity_ = count_;

        //выделяем память под буферный массив
        Type *tmp_mas = new Type[capacity_];

        //копируем в буферный массив элементы из текущего массива
        for (size_t i = 0; i < count_; i++) {
            tmp_mas[i] = array_[i];
        }

        //очищаем память основного массива
        if (array_ != nullptr) {
            delete[] array_;
        }

        //копируем буферный массив в новый основной
        array_ = tmp_mas;
    }
}

//вовзращает ссылку на элемент в позиции index
template<typename Type>
Type & MyVector<Type>::at(std::size_t index) {
    assert(index >= 0 && index < count_);
    return array_[index];
}

//прочитал, что такого нет
//возвращает константную ссылку на элемент в позиции index
template<typename Type>
const Type & MyVector<Type>::at(std::size_t index) const {
    assert(index >= 0 && index < count_);
    return array_[index];
}

//вовзращает ссылку на элемент в позиции index
template<typename Type>
Type & MyVector<Type>::operator[](std::size_t index) {
    return array_[index];
}


//возвращает константную ссылку на элемент в позиции index
template<typename Type>
const Type & MyVector<Type>::operator[](std::size_t index) const {
    return array_[index];
}

//функция вывода в консоль
template<typename T>
std::ostream & operator<<(std::ostream & out, const MyVector<T> &v) {
    if (v.empty()) {
        out << "empty";
    }

    for (size_t i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    
    return out;
}


//***************************************************************************//

#endif // MYVECTOR_HPP
