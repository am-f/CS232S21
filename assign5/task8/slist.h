#ifndef _slist_H_
#define _slist_H_

#include <stdint.h>
#include "snode.h"

struct slist;

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist* slist_create();

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_back(struct slist *l, void * data, int size);

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, void * data, int size);

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, void * data);

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l);

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l);

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l);
/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 */
void slist_delete(struct slist *l, void * data, int size);


#endif // _slist_H_
