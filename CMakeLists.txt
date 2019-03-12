cmake_minimum_required(VERSION 3.5)
project(HashTrie)
set(CMAKE_CXX_STANDARD 14)
add_executable(HashTrie main.cpp HashTrie/Trie/Node.cpp HashTrie/Trie/Node.h HashTrie/Trie/Trie.cpp HashTrie/Trie/Trie.h HashTrie/HashTrie.cpp HashTrie/HashTrie.h TxtReader/TxtReader.cpp TxtReader/TxtReader.h HashCollection/HashCollection.h)

