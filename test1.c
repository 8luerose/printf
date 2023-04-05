

//테스트 파일 입니다. 사용 후 삭제하세요.

//테스트1
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		bytes;
	int		past_bytes;
	char	c;

	va_start(ap, format);
	while (*format)
	{
		past_bytes = bytes;
		if (*format == '%')
		{
			c = *(format + 1);
			ft_check_argv(c, &ap, &bytes);
		}
		else
		{
			c = write(1, format, sizeof(char));
			bytes += c;
		}
		if (past_bytes > bytes)
		{
			bytes = -1;
			va_end(ap);
			return (bytes);
		}
		format++;
	}
	va_end(ap);
	return (bytes);
}
