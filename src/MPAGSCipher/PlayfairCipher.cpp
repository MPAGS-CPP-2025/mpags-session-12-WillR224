#include "PlayfairCipher.hpp"

#include <algorithm>
#include <string>

/**
 * \file PlayfairCipher.cpp
 * \brief Contains the implementation of the PlayfairCipher class
 */

PlayfairCipher::PlayfairCipher(const std::string& key)
{
    this->setKey(key);
}

void PlayfairCipher::setKey(const std::string& key)
{
    // Store the original key
    key_ = key;

    // Append the alphabet to the key
    key_ += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Make sure the key is upper case
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    auto iter = std::remove_if(std::begin(key_), std::end(key_),
                               [](const char c) { return !std::isalpha(c); });

    key_.erase(iter, std::end(key_));

    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   [](const char c) { return (c == 'J') ? 'I' : c; });

    std::string encountered{};
    auto iter2 = std::remove_if(std::begin(key_), std::end(key_),
                                [&encountered](const char c) {
                                    if (encountered.find(c) == std::string::npos) {
                                        encountered += c;
                                        return false;
                                    } else {
                                        return true;
                                    }
                                });
    key_.erase(iter2, std::end(key_));

    // Remove non-alphabet characters

    // Change J -> I

    // Remove duplicated letters

    // Store the coordinates of each letter
}

std::string PlayfairCipher::applyCipher(const std::string& inputText,
                                        const CipherMode /*cipherMode*/) const
{
    // Create the output string, initially a copy of the input text
    std::string outputText{inputText};

    // reorder string and return iter to start of chars to erase

    // Find repeated characters and add an X (or a Q for repeated X's)

    // If the size of the input is odd, add a trailing Z

    // Loop over the input bigrams

    // - Find the coordinates in the grid for each bigram

    // - Apply the rules to these coords to get new coords

    // - Find the letters associated with the new coords

    // - Make the replacements

    // Return the output text
    return outputText;
}
