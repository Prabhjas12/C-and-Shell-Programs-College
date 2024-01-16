#include "growing_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 1

struct Table table;

int add_record(Record new_record) {
    if (table.nval == table.max) {
        // Array is full, need to grow
        table.max *= 2;
        table.record = realloc(table.record, sizeof(Record) * table.max);
    }

    int index = table.nval;
    table.record[index] = new_record;
    table.nval++;

    return index;
}

int del_record(const char *name) {
    for (int i = 0; i < table.nval; i++) {
        if (strcmp(table.record[i].name, name) == 0) {
            // Match found, move records to preserve order
            memmove(&table.record[i], &table.record[i + 1], (table.nval - i - 1) * sizeof(Record));
            table.nval--;
            return 1; // Record deleted successfully
        }
    }

    return 0; // No matching record found
}

int get_id(const char *name) {
    for (int i = 0; i < table.nval; i++) {
        if (strcmp(table.record[i].name, name) == 0) {
            return table.record[i].id;
        }
    }

    return 0; // No matching record found
}

Record get_record(int index) {
    return table.record[index];
}

int main() {
    table.nval = 0;
    table.max = INIT_SIZE;
    table.record = malloc(sizeof(Record) * table.max);

    // test add_record
    Record r1 = {"Alice", 1};
    Record r2 = {"Bob", 2};
    Record r3 = {"Charlie", 3};
    int i1 = add_record(r1);
    int i2 = add_record(r2);
    int i3 = add_record(r3);
    printf("added records at indices %d, %d, %d\n", i1, i2, i3);

    // test get_id and get_record
    int id = get_id("Bob");
    Record r = get_record(i2);
    printf("record at index %d: name=%s, id=%d\n", i2, r.name, r.id);
    printf("record with name 'Bob': id=%d\n", id);

    // test del_record
    int success = del_record("Bob");
    printf("deleted record with name 'Bob': %d\n", success);
    id = get_id("Bob");
    printf("record with name 'Bob': id=%d\n", id);

    free(table.record);
    return 0;
}
/*
Output for the above testing code:

added records at indices 0, 1, 2
record at index 0: name=Alice, id=1
record with name 'Bob': id=2
deleted record with name 'Bob': 1
record with name 'Bob': id=0


*/
