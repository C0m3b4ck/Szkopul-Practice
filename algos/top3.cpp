        // check if meets top 3
        if (tmp > top_3[0]) // if greater than 1st
        {
            short tmp2 = top_3[1];
            top_3[1] = top_3[0];
            top_3[0] = tmp;
            top_3[2] = tmp2;
            cout << top_3[0] << " " << top_3[1] << " " << top_3[2] << "\n"; // debug print
        }
        else if (!(tmp > top_3[0]) && tmp > top_3[1]) // greater than 2nd
        {
            top_3[2] = top_3[1];
            top_3[1] = top_3[2];
            cout << top_3[0] << " " << top_3[1] << " " << top_3[2] << "\n"; // debug print
        }
        else if (!(tmp > top_3[0]) && !(tmp > top_3[1] && tmp > top_3[2])) //greater than 3rd
        {
            top_3[2] = tmp;
        }