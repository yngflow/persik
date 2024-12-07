#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void push_back(int value) {
        if (!head) {
            head = new Node(value);
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
    }

    bool has_palindrome() {
        Node* temp = head;
        while (temp) {
            if (is_palindrome(temp->value)) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void remove_primes() {
        while (head && is_prime(head->value)) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }

        Node* temp = head;
        while (temp && temp->next) {
            if (is_prime(temp->next->value)) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
    }

    void duplicate_ending_with_zero() {
        Node* temp = head;
        while (temp) {
            if (temp->value % 10 == 0) {
                Node* duplicate = new Node(temp->value);
                duplicate->next = temp->next;
                temp->next = duplicate;
                temp = duplicate->next;
            } else {
                temp = temp->next;
            }
        }
    }

    void sort_descending() {
        std::vector<int> values;
        Node* temp = head;

        while (temp) {
            values.push_back(temp->value);
            temp = temp->next;
        }

        std::sort(values.begin(), values.end(), std::greater<int>());

        temp = head;
        for (int value : values) {
            temp->value = value;
            temp = temp->next;
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    void clear() {
        while (head) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }

private:
    bool is_palindrome(int num) {
        int original = num, reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return original == reversed;
    }

    bool is_prime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= std::sqrt(num); ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
};

int main() {
    LinkedList list;

    std::cout << "Введите последовательность натуральных чисел (0 для завершения ввода): ";
    int num;
    while (std::cin >> num && num > 0) {
        list.push_back(num);
    }

    if (list.has_palindrome()) {
        list.remove_primes();
        list.duplicate_ending_with_zero();
    } else {
        list.sort_descending();
    }

    std::cout << "Результат: ";
    list.print();

    list.clear();
    return 0;
}
