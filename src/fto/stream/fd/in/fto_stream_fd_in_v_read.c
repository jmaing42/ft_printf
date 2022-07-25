#include "fto_stream_fd_in_v.h"

#include "unistd.h"

t_err	fto_stream_fd_in_v_read(
	t_fto_stream_fd_in *self,
	char *buffer,
	size_t length,
	size_t *read_bytes
)
{
	const ssize_t	result = read(self->fd, buffer, length);

	if (result == -1)
		return (true);
	*read_bytes = (size_t)result;
	return (false);
}