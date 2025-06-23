# импортируем библиотеки
import cv2
import numpy as np

# загружаем и показываем изображение
image = cv2.imread("test2.jpg")
cv2.imshow("Original", image)
cv2.waitKey(0)

# добавляем размытие (для удаления шума) и показываем
blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
cv2.imshow("Blurred", blurred_image)
cv2.waitKey(0)

# преобразуем rgb в hsv формат и показываем
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)
cv2.imshow("HSV", hsv_image)
cv2.waitKey(0)

# диапазон зеленого цвета в hsv формате (для его поиска)
hsv_min = np.array((36, 25, 25), np.uint8)
hsv_max = np.array((70, 255, 255), np.uint8)

# создаем маску для зеленых объектов (они будут выделены белым на черном) и показываем
green_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)
cv2.imshow("Green Mask", green_mask)
cv2.waitKey(0)

# ищем контуры фигур
contours, hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# начинаем перебор полученных контуров
for contour in contours:
    x, y, w, h = cv2.boundingRect(contour) # получаем координаты ограничивающего прямоугольника
    center_x = int(x + w / 2) # вычисляем координаты центра по x
    center_y = int(y + h / 2) # вычисляем координаты центра по y
    cv2.circle(image, (center_x, center_y), 5, (0, 0, 255), -1) # рисуем красную точку в центре

# показываем конечный результат
cv2.imshow("Result with Centers", image)
cv2.waitKey(0)

# закрываем все окна
cv2.destroyAllWindows()
