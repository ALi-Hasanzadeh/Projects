#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Yaddaşı təmizləyir
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

	// Siyahını çap edir 10-dan 20-ə kimi
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }

    // Sonuna əlavə et
    void append(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Əvvəlinə əlavə et
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Verilən elementdən sonra əlavə et
    void insertAfter(int target, int value) {
        Node* current = head;
        while (current != nullptr && current->data != target) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << target << " tapilmadi." << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;
    }

    // Verilən elementi sil
    void deleteNode(int target) {
        if (head == nullptr) return;

        // İlk element silinirsə
        if (head->data == target) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = head;
        Node* current = head->next;
        while (current != nullptr && current->data != target) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) return; // nəticə tapılmadı

        prev->next = current->next;
        delete current;
    }

    // Axtarış etmək
    void search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Element tapildi." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Element tapilmadi." << endl;
    }

	// Uzunluğu tapmaq
    void getLength() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        cout << "List length = " << count << endl;
    }

    // Maximum və minimum
    void findMaxMin() {
        if (head == nullptr) {
            cout << "Siyahi bosdur." << endl;
            return;
        }

        int maxVal = head->data;
        int minVal = head->data;

        for (Node* current = head->next; current != nullptr; current = current->next) {
            if (current->data > maxVal) maxVal = current->data;
            if (current->data < minVal) minVal = current->data;
        }

        cout << "Max: " << maxVal << endl;
        cout << "Min: " << minVal << endl;
    }

    // Siyahını tərsinə çevir
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }
};
