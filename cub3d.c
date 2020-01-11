/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrignol <mbrignol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:07:41 by mbrignol          #+#    #+#             */
/*   Updated: 2020/01/09 16:30:55 by mbrignol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int wrong_extention(char *str)
{
    int len;

    if ((len = ft_strlen(str)) <= 4)
        return (0);
    if (ft_strnstr(str + len - 4, ".cub", 4) == NULL)
        return (0);
}

int open_file_description(t_data *data, int *fd, char *str)
{
    if (!(wrong_extention(str)))
        return (return_error(0, data, "Error\nWrong map extention\n"));
    if (!((*fd) = open(str, O_RDONLY)))
        return (return_error(0, data, "Error\n"));
}

int main(int argc, char **argv)
{
    t_data *data;
    int fd;

    data = malloc(sizeof(t_data));
    data->player = malloc(sizeof(t_player));
    data->info = malloc(sizeof(t_info));
    data->image = malloc(sizeof(t_image));
    data->tex = malloc(sizeof(t_texture));
	initialize_struct_texture(data);
    if (argc < 2 || argc > 3)
        return (return_error(1, data, "Bad arguments\n"));
    if (!(open_file_description(data, &fd, argv[1])))
        return (return_error(1, data, "Can't open map\n"));
    if ((data->mlx_ptr = mlx_init()) == NULL)
        return (return_error(1, data, "Can't init mlx\n"));
    if (!(info_header_cub(fd, data)))
        return (return_error(1, data, "Parsing Header\n"));
    if (!(load_texture(data)))
        return (return_error(1, data, "Cant load textures\n"));
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, data->info->width, data->info->height, "Cub3D")))
		return (return_error(1, data, "Can't create window\n"));
	if ((create_image(data)) == 0)
		return (return_error(1, data, "Error images\n"));
    if (!(check_map(fd, data)))
        return (return_error(1, data, "Parsing map\n"));
	display(data);
    if (argc == 3 && ft_strnstr(argv[2], "-save", 5))
    {
        save_bmp(data);
        printf("AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH\n");
        exit(1);
        return (1);
    }
    mlx_hook(data->win_ptr, 17, 1L << 0, close_red_button, (void*)data);
    mlx_hook(data->win_ptr, 2, 1L << 0, get_event, (void*)data);
    mlx_loop(data->mlx_ptr);
}