/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:59:14 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/20 17:33:42 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
	int fd[2];
	char	buffer[10];
//	close(0); //close the 0 channel.
	if (pipe(fd) == -1) // pipe(fd) system call pipe: now the tube exists
		return (1);

	write(fd[1], "42", 2); //write on WRITING SIDE
	read(fd[0], buffer, 2); // read on READING SIDE
	buffer[2] = '\0';
	ft_printf("Received from tube: %s\n", buffer);
	ft_printf("FD readding: %d, FD Writing: %d\n", fd[0], fd[1]);

	return (0);
}
/*
 
 *
 La pipe non è un'entità astratta, ma un trasloco fisico di dati gestito dal 
 Kernel
 MANO SINISTRA (Indice 0)            MANO DESTRA (Indice 1)
      +-----------------------+           +-----------------------+
      |  PRENDE (Riceve)      |           |  METTE (Invia)        |
      |       READ            | <=======  |      WRITE            |
      +-----------------------+           +-----------------------+
                 ^                                   |
                 |          [ DENTRO IL TUBO ]       |
                 +-----------------------------------+*


Riassunto definitivo dell'azione write:
Cosa usi nel codice		Dove vanno i dati 	Chi li può vedere
write(fd[1], ...)		Dentro la pancia del tubo (RAM)
							Solo chi legge da
							fd[0]
write(1, ...)			Sul tuo terminale (Schermo)
							Tu, con i tuoi occhi
write(file_fd, ...)		Dentro un file sul disco fisso
							Tu, se apri il file dopo

C'è una differenza fondamentale nel modo in cui agiscono:

write ha bisogno che tu gli dia la "merce" (i dati sono già pronti nella tua
RAM).

read ha bisogno che tu gli dia lo "spazio" (il buffer è un contenitore vuoto
che aspetta di essere riempito).

*/
