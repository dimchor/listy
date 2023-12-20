# Listy

## Summmary
Listy is a small list library that accepts *any*[^1] kind of data. This is a 
modified version of a previous list library made by me as an assignment for a 
university course.

## Features
Listy offers neat features, namely:
- the data is sorted,
- the data can be inserted (copied) or emplaced (moved),
- list items can be removed *en masse* (`LISTY_remove_if()` or `LISTY_clear()`),
- the list is reversable,
- the list manages its own memory (which should be obvious)

[^1]: Through the use of `void*`