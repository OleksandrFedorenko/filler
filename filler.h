/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:18:28 by afedoren          #+#    #+#             */
/*   Updated: 2018/09/22 13:18:30 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BUFF_SIZE 1
# include <fcntl.h>
# include <ctype.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

# define FILLER_H
# define RESET  "\x1B[0m"
# define MAG 	"\x1B[38;5;134m"
# define CYAN   "\x1B[36m"
# define GREEN  "\x1B[32m"
# define YELLOW "\x1B[33m"
# define LIGHT  "\x1B[38;5;225m"
# define SPEC  "\x1B[38;5;215m"

typedef struct	s_filler
{
	char		my_p;
	char		opp_p;

	int			map_size_x;
	int			map_size_y;

	char		**map;
	char		**piece;

	int			p_size_x;
	int			p_size_y;

	int			m_x;
	int			m_y;

	int			p_x;
	int			p_y;

	int			final_x;
	int			final_y;

	int			last_x;
	int			last_y;

	int			enem_dist;
	int			enem_dist_tmp;
	int			tmp;
	int			enem_x;
	int			enem_y;

	int			find_x;
	int			find_y;
	int			find_dist;
	int			one_x;
	int			one_y;

}				t_struct;

typedef struct	s_visual
{
	int			o;
	int			x;
}				t_visual;

void			*ft_memalloc(size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
int				get_next_line (const int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcat(char *s1, const char *s2);
void			*ft_memset(void *b, int c, size_t len);
void			what_player(t_struct *list);
char			*ft_strstr(const char *big, const char *little);
int				all_about_map(t_struct *list);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
void			size_map(t_struct *list);
void			ft_make_zero_struct(t_struct *list);
void			malloc_map(t_struct *list);
char			*ft_strcpy(char *dst, const char *src);
void			fill_map(t_struct *list);
void			all_about_piece(t_struct *list);
void			size_piece(t_struct *list);
void			malloc_piece(t_struct *list);
void			fill_piece(t_struct *list);
void			algorithm(t_struct *list);
void			main_loop(t_struct *list);
int				can_put(t_struct *list);
int				check_space(t_struct *list);
int				best_choice(t_struct *list);
void			exit_prog(t_struct *list);
int				in_map(t_struct *list);
void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			find_opp(t_struct *list);
size_t			ft_abs(int n);
void			dist_stars_opp(t_struct *list);
void			check_one(t_struct *list);
void			distance(t_struct *list);
int				check_two(t_struct *list, int y, int x);
int				ft_tolower(int c);
int				yes(t_struct *list, int count, int y, int x);
int				no(t_struct *list);
void			dist_stars_opp_1(t_struct *list);
void			clean(t_struct *list);
void			clean_map(t_struct *list);

char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnew(size_t size);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcat(char *s1, const char *s2);
void			check_score_x(char *line, t_visual *list);
void			check_score_o(char *line, t_visual *list);
void			make_winner(t_visual *list);
void			check_one_visual(char *line);
void			free_arr(char **arr, int size);
#endif
