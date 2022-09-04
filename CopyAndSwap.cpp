#include <iostream>
#include <algorithm>

class Container
{
public:
    Container() = default;

    ~Container()
    {
        delete[] this->array;
    }

    Container(size_t size, uint8_t* array): size(size)
    {
        this->array = new uint8_t[size];
        memcpy(this->array, array, size);
    }

    Container(const Container& other): Container(other.size, other.array)
    {
    }


    Container& operator=(const Container& other)
    {
        if (this != &other)
        {
            Container(other).swap(*this);
        }

        return *this;
    }

    void print() 
    {
        for (size_t i = 0; i < this->size; i++) 
        {
            std::cout << this->array[i] << ' ';
        }
        std::cout << std::endl;
    }

private:
    void swap(Container& other)
    {
        std::swap(this->array, other.array);
        std::swap(this->size, other.size);
    }

private:
    size_t size;
    uint8_t* array;
};

int main()
{
    uint8_t first_byte_array[] = { '2', '1', 'a', '0', '4', 'f' };
    uint8_t second_byte_array[] = { '2', '2', '2', '2', '2' };

    Container first_container(sizeof(first_byte_array) / sizeof(first_byte_array[0]), first_byte_array);
    first_container.print();

    Container second_container(sizeof(second_byte_array) / sizeof(second_byte_array[0]), second_byte_array);
    second_container.print();

    second_container = first_container;

    first_container.print();
    second_container.print();

    return 0;
}
