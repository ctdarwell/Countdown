# Countdown
Simple wordgame in C++

This is my first attempt at programming in C++ to indicate some basic techniques. The program first asks you to select nine letters (either vowel [v] or consonant [c]), which it chooses randomly(!!). It then gives a 30 second timer when players 1 & 2 think of their longest word. Finally, the program accepts both words from the players, evaluates if they are legal (i.e. by checking all letters are contained within the initial selection), then indicates the winner who found the longest legal word. It's very simple, it doesn't check if a word is in the dictionary, doesn't check if a player uses a letter more than once, nor does it disproportionately select common letters (e.g. T, S, R, E, A) over uncommon ones (e.g. Q, Z, X, J). 
