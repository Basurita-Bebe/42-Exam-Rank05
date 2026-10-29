/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 17:38:46 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/10/27 17:59:56 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** How to compile (run from 04_life/):
**   cc -Wall -Wextra -Werror my_solution/life.c -o life
**   echo 'dxss' | ./life 3 3 1 | cat -e
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int     w, h, iter;
    char    *board;
    int     x = 0, y = 0, drawing = 0;  // 0 = lifted, 1 = lowered
    char    c;
    char    *next;
    int     count;

    if (argc != 4)
        return (1);
    w = atoi(argv[1]);
    h = atoi(argv[2]);
    iter = atoi(argv[3]);
    board = calloc(w * h, 1);           // all cells start at 0
    if (!board)
        return (1);
    
    // 1. draw: read the commands
    while (read(0, &c, 1) > 0)
    {
        if (c == 'w' && y > 0)
            y--;
        else if (c == 's' && y < h - 1)
            y++;
        else if (c == 'a' && x > 0)
            x--;
        else if (c == 'd' && x < w - 1)
            x++;
        else if (c == 'x')
            drawing = !drawing;
        if (drawing)
            board[y * w + x] = 1;
    }
    
    // 2. simulate iter items
    for (int it = 0; it < iter; it++)
    {
        next = calloc(w * h, 1);
        if (!next)
            return (free(board), 1);
        for (int i = 0; i < h; i++)         // row
        {
            for (int j = 0; j < w; j++)     // column
            {
                count = 0;
                for (int di = -1; di <= 1; di++)
                    for (int dj = -1; dj <= 1; dj++)
                        if ((di || dj)
                            && i + di >= 0 && i + di < h
                            && j + dj >= 0 && j + dj < w)
                            count += board[(i + di) * w + (j + dj)];
                if (board[i * w + j])
                    next[i * w + j] = (count == 2 || count == 3);
                else
                    next[i * w + j] = (count == 3);
            }
        }
        free(board);
        board = next;
    }
    
    // 3. print
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
            putchar(board[y * w + x] ? 'O' : ' ');
        putchar('\n');
    }
    free(board);
    return (0);
}