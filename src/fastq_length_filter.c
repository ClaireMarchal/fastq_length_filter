/******************************************************************************/
/*                                                                            */
/*    Copyright 2015 Claire Marchal at Universite Paris Diderot (FRANCE)      */
/*                                                                            */
/*    This program is free software: you can redistribute it and/or modify    */
/*    it under the terms of the GNU General Public License as published by    */
/*    the Free Software Foundation, either version 3 of the License, or       */
/*    (at your option) any later version.                                     */
/*                                                                            */
/*    This program is distributed in the hope that it will be useful,         */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with this program. If not, see <http://www.gnu.org/licenses/>.    */
/*                                                                            */
/******************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

static void	ft_strdel(char **as)
{
  if (as != NULL)
    {
      *as = NULL;
      free(*as);
      as = NULL;
    }
}

static int	ft_test(char **block, unsigned int l)
{
  int	n;

  if (strlen(block[1]) != l + 1 || strlen(block[1]) != strlen(block[3]))
    return (0);
  n = 0;
  while (n < 4)
    {
      printf("%s", block[n]);
      ft_strdel(&(block[n]));
      n++;
    }
  return (1);
}

static void	ft_filter(int l, char *input, int *reads)
{
  FILE		*fd_i;
  int		n;
  int		i;
  size_t	v;
  char		**block;

  block = (char **)malloc(3000 * sizeof(char *));
  if (block == NULL)
    return;
  n = 0;
  v = 500;
  while (n < 5)
    {
      block[n] = (char *)malloc(v * sizeof(char));
      if (block[n] == NULL)
	return;
      n++;
    }
  if ((fd_i = fopen(input, "r")) == NULL)
    {
      fprintf(stderr, "\nError: %s\n", strerror(errno));
      return;
    }
  i = 1;
  while (i > 0)
    {
      n = 0;
      while (n < 4 && i > 0)
	{
	  if((i = getline(&(block[n]), &v, fd_i)) == -1 && errno != 0)
	    {
	      fprintf(stderr, "\nError: %s\n", strerror(errno));
	      return;
	    }
	  n++;
	}
      if (i > 0)
	*reads = *reads + ft_test(block, l);
    }
}

void	ft_licence(void)
{
  fprintf(stderr, "\
\n\
**********************************************************************************\n\
*    Copyright 2015 Claire Marchal at Universite Paris Diderot (FRANCE)          *\n\
*                                                                                *\n\
*    This program is free software: you can redistribute it and/or modify        *\n\
*    it under the terms of the GNU General Public License as published by        *\n\
*    the Free Software Foundation, either version 3 of the License, or           *\n\
*    (at your option) any later version.                                         *\n\
*                                                                                *\n\
*    This program is distributed in the hope that it will be useful,             *\n\
*    but WITHOUT ANY WARRANTY; without even the implied warranty of              *\n\
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *\n\
*    GNU General Public License for more details.                                *\n\
*                                                                                *\n\
*    You should have received a copy of the GNU General Public License           *\n\
*    along with this program. If not, see <http://www.gnu.org/licenses/>.        *\n\
*                                                                                *\n\
**********************************************************************************\n\
\n\
");
}

void	ft_help(void)
{
  fprintf(stderr, "\
fastq_length_filter\n\
\n\
The aim of this tool is to extract reads of specified length of a fastq, and \n\
to generate a new fastq with the reads of specified length on stdout.\n\
Be aware that this tool doesn't check the format nor the integrity of the input \n\
file.\n\
\n\
It takes a read length and a fastq file as input, and prints the reads of the \n\
specified length on stdout.\n\
\n\
usage: fastq_length_filter length input.fastq > output.fastq\n\
\n\
");
}

int	main(int argc, char **argv)
{
  int	reads;

  reads = 0;
  ft_licence();
  ft_help();
  if (argc == 3)
    {
      fprintf(stderr, "Please wait, processing data...");
      ft_filter(atoi(argv[1]), argv[2], &reads);
      if (errno == 0)
	fprintf(stderr, "\njob processed\n%d reads have been identified\n", reads);
    }
  else
    fprintf(stderr, "Please enter a valid command\n");
  return (0);
}
