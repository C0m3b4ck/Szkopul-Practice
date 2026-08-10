    sort(score_pairs.begin(), score_pairs.end(), [](const auto& a, const auto& b) {
        if (get<1>(a) != get<1>(b))  // different scores
            return get<1>(a) > get<1>(b);  // higher score first
        return get<2>(a) > get<2>(b);      // tie-break: higher mul1 first
    }); // sorts based on element 1, then on element 2