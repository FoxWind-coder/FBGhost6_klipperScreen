#include <linux/bitops.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <video/mipi_display.h>
#include "fbtft.h"

#define DRVNAME "fb_st7796s"

#define ST7796S_MADCTL_MY  0x80 // Порядок адресации строк
#define ST7796S_MADCTL_MX  0x40 // Порядок адресации столбцов
#define ST7796S_MADCTL_MV  0x20 // Обмен строк/столбцов
#define ST7796S_MADCTL_ML  0x10 // Порядок обновления вертикальных строк
#define ST7796S_MADCTL_BGR 0x08 // Порядок цветов RGB-BGR
#define ST7796S_MADCTL_RGB 0x00
#define ST7796S_MADCTL_MH  0x04 // Порядок обновления горизонтальных строк
#define ST7796S_COLOR      ST7796S_MADCTL_BGR

// Остальные определения команд и регистров

#define TFT_NO_ROTATION           (ST7796S_MADCTL_MV)
#define TFT_ROTATE_90             (ST7796S_MADCTL_MX)
#define TFT_ROTATE_180            (ST7796S_MADCTL_MV | ST7796S_MADCTL_MX | ST7796S_MADCTL_MY)
#define TFT_ROTATE_270            (ST7796S_MADCTL_MY)

/**
 * init_display() - инициализация контроллера дисплея
 */
static int init_display(struct fbtft_par *par)
{
	// Ваш код инициализации дисплея
}

/**
 * blank() - отключение дисплея
 */
static int blank(struct fbtft_par *par, bool on)
{
	// Ваш код управления отображением
}

static struct fbtft_display display = {
	.regwidth = 8,
	.width = 480,
	.height = 320,
	.fbtftops = {
		.init_display = init_display,
		.blank = blank,
	},
};

static struct spi_device_id st7796s_id[] = {
	{ "st7796s", 0 },
	{ },
};
MODULE_DEVICE_TABLE(spi, st7796s_id);

static struct spi_driver st7796s_spi_driver = {
	.driver = {
		.name = DRVNAME,
	},
	.probe = fbtft_spi_probe,
	.remove = fbtft_spi_remove,
	.id_table = st7796s_id,
};

module_spi_driver(st7796s_spi_driver);

MODULE_ALIAS("spi:st7796s");
MODULE_DESCRIPTION("FB driver for the ST7796S LCD Controller");
MODULE_AUTHOR("NNN");
MODULE_LICENSE("GPL");
