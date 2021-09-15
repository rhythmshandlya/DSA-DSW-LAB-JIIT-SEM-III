    if (temp->val == 0)
        {
            temp = temp->next;
            continue;
        }
        if (temp->exp == 0)
        {
            cout << temp->val << " ";
            temp = temp->next;
            continue;
        }