// Sequence.cpp

#include "Sequence.h"
#include <iostream>
#include <stdexcept>

// Default constructor
Sequence::Sequence() : desc(""), seq("") {}

// Parameterized constructor
Sequence::Sequence(const std::string& desc_str, const std::string& seq_str) : desc(desc_str), seq(seq_str) {}

// Error checking method
void Sequence::check() const {
    // If the description indicates a random seed, skip the check.
    if (desc.find("> rand iseed=") == 0) {
        return; // Skip the check for random seed sequences.
    }
    // Check for invalid characters in seq for typical protein sequences.
    if (seq.find_first_not_of("ACDEFGHIKLMNPQRSTVWY") != std::string::npos) {
        throw std::invalid_argument("invalid character in sequence");
    }
}

// Input operator for reading FASTA format
std::istream& operator>>(std::istream& is, Sequence& s) {
    std::string line, temp_seq;
    getline(is, s.desc); // Read the description line
    while (getline(is, line) && !line.empty()) {
        temp_seq += line;
    }
    s.seq = temp_seq;
    s.check(); // Validate sequence
    return is;
}

// Output operator for writing FASTA format
std::ostream& operator<<(std::ostream& os, const Sequence& s) {
    // Output the description.
    os << s.desc << "\n";
    // Output the sequence in chunks of 70 characters if it's not empty.
    if (!s.seq.empty()) {
        size_t pos = 0;
        while (pos < s.seq.length()) {
            os << s.seq.substr(pos, 70) << "\n";
            pos += 70;
        }
        // Add an extra newline to separate sections.
        os << "\n";
    }
    
    return os;
}

// Friend function to find MUM
Sequence findMUM(const Sequence& s1, const Sequence& s2) {
    std::string::size_type max_length = 0;
    std::string mum = "";
    std::string::size_type pos1 = std::string::npos, pos2 = std::string::npos;
    
    for (std::string::size_type i = 0; i + 19 < s1.seq.length(); i++) {
        for (std::string::size_type len = 20; i + len <= s1.seq.length(); len++) {
            std::string sub = s1.seq.substr(i, len);
            if (s2.seq.find(sub) != std::string::npos && // Exists in s2
                s1.seq.find(sub, i + 1) == std::string::npos && // Unique in s1
                s2.seq.find(sub, s2.seq.find(sub) + 1) == std::string::npos) { // Unique in s2
                // Check if it's the longest found so far
                if (len > max_length) {
                    max_length = len;
                    mum = sub;
                    pos1 = i;
                    pos2 = s2.seq.find(sub);
                }
            }
        }
    }
    
    if (max_length == 0) {
        return Sequence(">No MUM found\n", "");
    } 
    else {
        std::string description = ">MUM pos1=" + std::to_string(pos1 + 1) + " pos2=" + std::to_string(pos2 + 1);
        return Sequence(description, mum);
    }
}

// Method to find the first mutation after a given position
std::string Sequence::findNextMutation(const Sequence& other, const int& pos) const {
    // Adjust 'pos' for 0-based indexing if the provided 'pos' is 1-based.
    auto startIndex = static_cast<std::string::size_type>(pos - 1);

    for (auto i = startIndex; i < std::min(seq.length(), other.seq.length()); ++i) {
        if (seq[i] != other.seq[i]) {
            // When we find a mutation, convert from 0-based indexing (C++ strings)
            // to 1-based indexing (biological sequences) by adding 1 to 'i'.
            return seq[i] + std::to_string(i + 1) + other.seq[i];
        }
    }
    return "no mutation found";
}