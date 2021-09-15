temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            delete temp;