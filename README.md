# Sentiment Analyzer Using NLP

## Project Overview
This C++ project is a Sentiment Analyzer that uses Natural Language Processing (NLP) to analyze the sentiment of a given text input. It reads a list of words and their associated sentiment scores from CSV files and then allows the user to input a text. The program calculates the sentiment score of the text by matching the words in the input text with the pre-defined words in the CSV files and their associated scores. The program then provides a sentiment score and a sentiment label (e.g., "Happy," "Upset," "Neutral") based on the overall sentiment of the input text.

## Project Components
The project consists of the following key components:

1. **Data Files**: The project reads two CSV files: `score.csv` containing sentiment scores and `words.csv` containing words associated with those scores.

2. **Data Structures**:
    - `node` structure: Represents a node in a linked list, which holds a word and its associated sentiment score.
    - `lists` class: Implements a linked list data structure for storing words and their sentiment scores.
    - `hash_table` class: Implements a hash table for efficient word lookup based on the word's hash.

3. **Main Functionality**:
    - Reading sentiment scores and words from CSV files.
    - Creating a hash table to store words and their scores.
    - Accepting user input and breaking it into individual words.
    - Calculating the sentiment score of the input text.
    - Providing a sentiment label based on the calculated score.

## How to Use
1. Prepare two CSV files: `score.csv` and `words.csv`. Each CSV file should have two columns: one for words and one for sentiment scores.
2. Compile the C++ program and run it.
3. Enter the text you want to analyze when prompted.
4. The program will display the sentiment score, comparative score, and a sentiment label for the input text.

## Sample Output
```
----------------SENTIMENT ANALYZER USING NLP----------------
Enter TEXT :

I am feeling happy today

Final score is : 5   Comparative : 1.25

Happy !!
```

## Requirements
- C++ compiler
- Input CSV files (`score.csv` and `words.csv`) with appropriate data

## Project Files
- `main.cpp`: The C++ source code for the sentiment analyzer.
- `score.csv`: Sample CSV file containing words and their sentiment scores.
- `words.csv`: Sample CSV file containing sentiment scores for words.

## Project Author
Fahad Yousuf

## Acknowledgments
This project was inspired by the need for a simple sentiment analysis tool using NLP techniques. It can serve as a starting point for more advanced sentiment analysis projects and can be extended to handle larger datasets and more complex NLP algorithms.
