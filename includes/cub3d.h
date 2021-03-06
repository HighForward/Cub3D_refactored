/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 05:13:46 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/23 07:43:07 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include "structures.h"
# include <math.h>

# define STEP 0.25f
# define VIEW 2.5f

t_data			*malloc_struct(void);
void			initialize_struct_texture(t_data *data);
int				handle_args(t_data *data, char **argv, int argc);
int				open_file_description(t_data *data, int *fd, char *str);
int				wrong_extention(char *str);
int				info_header_cub(int fd, t_data *data);
int				parse_map(t_data *data, char *s, int *i);
int				check_info_textures(char *str, t_data *data);
int				check_info(char *str, t_data *data);
int				check_info_c_f(char *str, t_data *data);
int				skip_space(char *str);
int				skip_space_virgule(char *str, int *i);
int				get_value_window(char *s, int *i);
void			check_full_screen(int *dest1, int *dest2);
int				parse_map_info_window(char *str, int *dest1, int *dest2,
		int start);
int				parse_info_textures(char *s, t_data *data);
int				parse_info_c_f(char *s, t_data *data);
int				get_texture_c_f(char *str, int i, int *color);
int				fill_full_map(t_data *data);
int				fill_last_line(t_data *data, char *line, int *secure);
int				fill_temp_map(t_data *data, char *line, char **temp);
int				fill_map(t_data *data, char *line, int *secure);
int				check_map(int fd, t_data *data);
int				is_valid_line(char *s);
void			cut_space(char **line);
int				free_entire_map(char **str);
int				create_image(t_data *data);
int				fill_textures(t_data *data, t_tex_info *tex_info);
int				load_texture(t_data *data);
int				map_is_not_close(t_data *data);
int				map_too_big(t_data *data);
int				check_map_parsing(t_data *data);
int				get_position(t_data *data);
void			set_position(t_data *data, t_index x, float step_player,
		int *player_there);
void			get_orientation(t_data *data, t_vector d, t_vector p);
void			display_hud(t_data *data);
void			display_dead_screen(t_data *data, int key);
t_color			c(int v);
int				convertrgb(int r, int g, int b);
int				get_darkness(int color, int percent);
int				get_transparency(t_data *data, int source, int destination);
int				degrade_couleur(int color, int x);
int				display_lifebar_bar(t_data *data);
int				display_lifebar(t_data *data);
void			print_map(t_data *data);
void			ft_putpixel(char *line, int i, t_data *data);
void			display_rekt(int x, int y, int color, t_data *data);
void			display_dir_map(t_data *data);
void			secure_vector(t_vector step, t_data *data, int i);
int				display_cross_around(t_data *data, int color);
int				display_cross_pixel(int x, int y, t_data *data, int color);
int				display_cross_circle(int x, int y, t_data *data, int color);
int				display_cross(t_data *data);
t_index			vec_i(int x, int y);
t_spawn_player	vec_s(int x, int y);
t_vector		vec(float x, float y);
int				size_map(char **str);
void			handle_secret_door(t_data *data, t_render *render, t_ray ray);
void			leave_secret_door(t_data *data);
void			take_damage(t_data *data, int value);
int				get_event(int key, t_data *data);
void			rotate_player(t_player *player, float angle);
void			move_front_back(t_data *data, float move);
void			move_side(t_data *data, float move);
void			direction(t_vector *v, float angle);
void			obstacle(t_data *data, float move);
int				save_bmp(t_data *data);
int				bmp_header(int save, int size, t_data *data);
void			put_int_in_char(unsigned char *begin, int val);
int				write_data(int file, t_data *data);
int				get_event(int key, t_data *data);
int				display(t_data *data, int key);
int				get_wall(t_data *data, t_ray ray);
void			get_wall_dda(t_data *data, t_render *render, t_ray ray);
void			load_line_buffer(t_data *data, t_render render, t_ray ray,
		int **buffer);
void			print_lines(t_data *data, t_ray ray, t_render render,
		int *buffer);
int				display_view(t_player *p, t_data *data);
int				display_line(t_data *data, float step, int i);
int				get_darkness(int color, int percent);
int				get_line(t_data *data, t_ray ray, t_render render);
t_tex_info		current_texture(t_data *data, t_render render);
void			display_sprite(t_data *data, t_ray ray);
void			side_x(t_render *render);
void			side_y(t_render *render);
void			hit_sprite(t_data *data, t_render *render);
int				free_and_return(int value, char *str);
int				return_error(int value, t_data *data, char *str);
int				return_string(int value, char *str);
int				return_string_free(int value, char *str);
int				close_red_button(t_data *game);
void			initialize_struct_texture(t_data *data);

#endif
