#include <iostream>

struct Node
    {
        int value;
        Node* next;
    };

class List
    {
        private:
            Node* head;

        public:
            List() {head = NULL;}
            int len = 0;

            void append_tail(int new_value)
                {
                    Node* new_node = new Node;
                    new_node->value = new_value;
                    new_node->next = NULL;

                    if(head == NULL)
                        {
                            head = new_node;
                        }

                    else
                        {
                            Node* current = head;

                            while(current->next != NULL)
                                {
                                    current = current->next;
                                }

                            current->next = new_node;
                        }

                    len ++;
                }

            void append_head(int new_value)
                {
                   Node* new_node = new Node;
                   new_node->value = new_value;
                   new_node->next = head;
                   head = new_node;
                   len ++;
                }

            int length()
                {
                    return len;
                }

            void print()
                {
                    Node* current = head;
                    while(current != NULL)
                        {
                            std::cout << current->value << std::endl;
                            current = current->next;
                        }
                }

            void delete_tail()
                {
                    if(head == NULL)
                        {
                            std::cout << "Error: Empty" << std::endl;
                        }
                    else
                        {
                            Node* current = head;
                            int i = 1;
                            while(i < len - 1)
                                {
                                    current = current->next;
                                    i ++;
                                }
                            delete current->next;
                            current->next = NULL;
                            len --;
                        }
                }

            void delete_head()
                {
                    if(head == NULL)
                        {
                            std::cout << "Error: Empty" << std::endl;
                        }
                    else
                        {
                            Node* bufer = head->next;
                            delete head;
                            head = bufer;
                            len --;
                        }
                }

            bool contains(int new_value)
                {
                    Node* current = head;
                    while(current != NULL)
                        {
                            if(current->value == new_value)
                                {
                                    return true;
                                }
                            current = current->next;
                        }
                    return false;
                }

            void delete_by_value(int new_value)
                {
                    if(contains(new_value) == false)
                        {
                            std::cout << "Error: don't contain " << std::endl;
                            return;
                        }
                    if(head->value == new_value)
                        {
                            delete_head();
                            return;
                        }
                    Node* current = head;
                    while(current->next->value != new_value)
                        {
                            current = current->next;
                        }
                    Node* bufer = current->next->next;
                    delete current->next;
                    current->next = bufer;

                };

            void delete_by_index(int index)
                {
                    if(index >= len)
                        {
                            std::cout << "Error: len <= index " << std::endl;
                            return;
                        }
                    if(index == 0)
                        {
                            delete_head();
                            return;
                        }
                    Node* current = head;
                    int currentNum = 1;
                    while(current && currentNum != index)
                        {
                            currentNum ++;
                            current = current->next;
                        }
                    Node* bufer = current->next->next;
                    delete current->next;
                    current->next = bufer;
                }
            void insert_by_index(int index, int new_value)
                {
                    if(index > len)
                        {
                            std::cout << "Error: len <= index " << std::endl;
                        }
                    else
                        {
                            Node* current = head;
                            int i = 0;
                            while(i < (index - 2))
                                {
                                    current = current->next;
                                    i ++;
                                }
                            Node* new_node = new Node;
                            new_node->value = new_value;
                            new_node->next = current->next->next;
                            current->next = new_node;
                        }
                }

            int operator[](int index)
                {
                    Node* current = head;
                    int currentNum = 0;
                    while(current && currentNum != index)
                        {
                            currentNum ++;
                            current = current->next;
                        }
                    if(index == currentNum)
                        {
                            int Value = current->value;
                            return Value;
                        }
                    else
                        {
                            std::cout << "Error: len <= index " << std::endl;
                            return 0;
                        }
                }
    };


int main()
{
    List A1;
    A1.append_tail(3);
    A1.append_tail(4);
    A1.append_tail(5);
    A1.append_tail(6);
    A1.print();
    return 0;
}
