/** 
 * file: bst.c - 
 * Author: Jodley Angrand(jsa6675) 
 */
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <string.h>
#include <strings.h> 
/**
 * bst_insert() --
 *     Allocate a node to hold a word and insert it into the tree.
 *
 * @param bp   - a pointer to the pointer to the root node of the
 *               tree to which this word will be added
 * @param word - string containing the word to be inserted
 * @param line - the line number where the word occurred in the input
 */
 void bst_insert( bstnode_t **bp, const char *word, int line ) { 
      if (*bp == NULL) {
         *bp = malloc(sizeof(bstnode_t));
         if (*bp == NULL) {
            return;
         }
         (*bp)->word = malloc(strlen(word) + 1);
         strcpy((*bp)->word, word);
         (*bp)->freq = 1;
         (*bp)->reflen = 1;
         (*bp)->refs = malloc(sizeof(unsigned int));
         (*bp)->refs[0] = line;
         (*bp)->left = NULL;
         (*bp)->right = NULL;
         return;

      }
      //word already exists so increment frequency and reference length and add reference
      if (strcasecmp(word, (*bp)->word) == 0) {
         (*bp)->freq++;
         (*bp)->reflen++;
         (*bp)->refs = realloc((*bp)->refs, (*bp)->reflen * sizeof(unsigned int));
         (*bp)->refs[(*bp)->reflen - 1] = line;
      }
      else if (strcasecmp(word, (*bp)->word) < 0) {
         //Word is smaller so go left
         bst_insert(&(*bp)->left, word, line);
      }
      else {
         //Word is larger so go right
         bst_insert(&(*bp)->right, word, line);
      }
   }

   /**
   * bst_traverse() -- performs an recursive in-order traversal of the tree and prints out the contents of the tree in the format:
   * word (Freq): ref1, ref2, ...
   * @param root - a pointer to the first node in the tree 
   */
void bst_traverse(const bstnode_t *root) {
   if ( root == NULL ){
      return;
   }

   bst_traverse(root->left);
   printf("%s (%u): ", root->word, root->freq);
   if(root->reflen > 0 ){
      printf("%u", root->refs[0]);

      for(unsigned int i = 1; i < root->reflen; i++){
         printf(", %u", root->refs[i]);
      }
   }
   printf("/n");

   bst_traverse(root->right);
}



/** 
* bst_cleanup() -- recursively clean up the tree 
* @param root - a pointer to the root node of the tree to clean up 
*/
void bst_cleanup(bstnode_t *root) {
   return;
}