import cv2 as cv
from tkinter import *
from PIL import ImageTk, Image
from copy import deepcopy
import numpy as np


class MainSolution():
    def __init__(self):
        self.image = cv.imread("g.jpg")
        self.imgray = None
        self.trsh1 = None
        self.trsh2 = None

    def original(self):
        img = Image.fromarray(self.image)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def filt(self):
        self.imgray = cv.cvtColor(cv.pyrMeanShiftFiltering(
            self.image, 15, 50), cv.COLOR_BGR2GRAY)
        img = Image.fromarray(self.imgray)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def local_threshold(self):
        ret, thresh1 = cv.threshold(self.imgray, 0, 255, cv.THRESH_BINARY_INV | cv.THRESH_OTSU)
        self.trsh1 = deepcopy(thresh1)
        img = Image.fromarray(thresh1)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def adaptive_threshold(self):
        thresh2 = cv.adaptiveThreshold(self.imgray, 255, cv.ADAPTIVE_THRESH_GAUSSIAN_C, cv.THRESH_BINARY, 11, 2)
        self.trsh2 = deepcopy(thresh2)
        img = Image.fromarray(thresh2)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def gaussian_filter(self):
        img = cv.GaussianBlur(self.trsh1, (5, 5), 0)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def bilateral_filter(self):
        img = cv.bilateralFilter(self.image, 9, 75, 75)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def median_filter(self):
        img = cv.medianBlur(self.trsh2, 5)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def gradient(self):
        img = cv.morphologyEx(self.trsh2, cv.MORPH_GRADIENT, cv.getStructuringElement(cv.MORPH_RECT, (5, 5)))
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def top_hat(self):
        img = cv.morphologyEx(self.trsh2, cv.MORPH_TOPHAT, cv.getStructuringElement(cv.MORPH_RECT, (5, 5)))
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def black_hat(self):
        img = cv.morphologyEx(self.trsh2, cv.MORPH_BLACKHAT, cv.getStructuringElement(cv.MORPH_RECT, (5, 5)))
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def erosion(self):
        img = cv.erode(self.trsh2, cv.getStructuringElement(cv.MORPH_RECT, (5, 5)))
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def dilation(self):
        img = cv.dilate(self.trsh2, cv.getStructuringElement(cv.MORPH_RECT, (5, 5)))
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def houk(self):
        img = cv.Canny(self.image, 100, 200)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def sobel(self):
        img = cv.Sobel(self.trsh2, cv.CV_8U, 1, 0, ksize=3)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def laplacian(self):
        img = cv.Laplacian(self.trsh2, cv.CV_8U, ksize=3)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def furie(self):
        img = cv.dft(self.trsh2)
        img = cv.magnitude(img[:, :, 0], img[:, :, 1])
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def counter_harmonic_mean_filter(self):
        img = cv.ximgproc.guidedFilter(self.trsh2, self.trsh2, 5, 0.1)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def canny(self):
        img = cv.Canny(self.trsh2, 100, 200)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def vincent(self):
        img = cv.ximgproc.thinning(self.trsh2)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def harris(self):
        img = cv.cornerHarris(self.trsh2, 2, 3, 0.04)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def shi_tomasi(self):
        img = cv.goodFeaturesToTrack(self.trsh2, 25, 0.01, 10)
        img = np.int0(img)
        for i in img:
            x, y = i.ravel()
            cv.circle(self.trsh2, (x, y), 3, 255, -1)
        img = Image.fromarray(self.trsh2)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def hough(self):
        img = cv.HoughLines(self.trsh2, 1, np.pi / 180, 200)
        for i in range(len(img)):
            rho = img[i][0][0]
            theta = img[i][0][1]
            a = np.cos(theta)
            b = np.sin(theta)
            x0 = a * rho
            y0 = b * rho
            x1 = int(x0 + 1000 * (-b))
            y1 = int(y0 + 1000 * (a))
            x2 = int(x0 - 1000 * (-b))
            y2 = int(y0 - 1000 * (a))
            cv.line(self.trsh2, (x1, y1), (x2, y2), (0, 0, 255), 2)
        img = Image.fromarray(self.trsh2)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)


    def roberts(self):
        img = cv.Sobel(self.trsh2, cv.CV_8U, 1, 0, ksize=3)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def prewitt(self):
        img = cv.Sobel(self.trsh2, cv.CV_8U, 1, 0, ksize=3)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def scharr(self):
        img = cv.Sobel(self.trsh2, cv.CV_8U, 1, 0, ksize=3)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def kirsh(self):
        img = cv.Sobel(self.trsh2, cv.CV_8U, 1, 0, ksize=3)
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def opening(self):
        img = cv.morphologyEx(self.trsh2, cv.MORPH_OPEN, cv.getStructuringElement(cv.MORPH_RECT, (5, 5)))
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)

    def closing(self):
        img = cv.morphologyEx(self.trsh2, cv.MORPH_CLOSE, cv.getStructuringElement(cv.MORPH_RECT, (5, 5)))
        img = Image.fromarray(img)
        img = img.resize((300, 300))
        return ImageTk.PhotoImage(img)


class MainApp():
    def __init__(self, master):
        self.master = master
        self.master.title("Image Processing")
        self.master.geometry("1440x820")
        self.master.resizable(False, False)
        self.master.configure(background="silver")

        self.solution = MainSolution()

        self.frame = Frame(self.master, bg="silver")
        self.frame.pack()

        self.label = Label(self.frame, text="Image Processing", font=("Arial", 20), bg="silver")
        self.label.grid(row=0, column=0, columnspan=4, pady=10)

        self.button1 = Button(self.frame, text="Original Image", font=("Arial", 12), bg="silver",
                              command=self.original_image)
        self.button1.grid(row=1, column=0, pady=10)

        self.button2 = Button(self.frame, text="Filt", font=("Arial", 12), bg="white",
                                command=self.filt)
        self.button2.grid(row=1, column=1, pady=10)

        self.button3 = Button(self.frame, text="Local Threshold", font=("Arial", 12), bg="white",
                                command=self.local_threshold)
        self.button3.grid(row=1, column=2, pady=10)

        self.button4 = Button(self.frame, text="Adaptive Threshold", font=("Arial", 12), bg="white",
                                command=self.adaptive_threshold)
        self.button4.grid(row=1, column=3, pady=10)

        self.button5 = Button(self.frame, text="Gausian", font=("Arial", 12), bg="white",
                                command=self.gaussian_filter)
        self.button5.grid(row=2, column=0, pady=10)

        self.button6 = Button(self.frame, text="Bilateral_filter", font=("Arial", 12), bg="white",
                                command=self.bilateral_filter)
        self.button6.grid(row=2, column=1, pady=10)

        self.button7 = Button(self.frame, text="Canny", font=("Arial", 12), bg="white",
                                command=self.canny)
        self.button7.grid(row=2, column=2, pady=10)

        self.button8 = Button(self.frame, text="Sobel", font=("Arial", 12), bg="white",
                                command=self.sobel)
        self.button8.grid(row=2, column=3, pady=10)

        self.button9 = Button(self.frame, text="Laplacian", font=("Arial", 12), bg="white",
                                command=self.laplacian)
        self.button9.grid(row=3, column=0, pady=10)

        self.button10 = Button(self.frame, text="Hough", font=("Arial", 12), bg="white",
                                command=self.hough)
        self.button10.grid(row=3, column=1, pady=10)

        self.button11 = Button(self.frame, text="Roberts", font=("Arial", 12), bg="white",
                                command=self.roberts)
        self.button11.grid(row=3, column=2, pady=10)

        self.button12 = Button(self.frame, text="Prewitt", font=("Arial", 12), bg="white",
                                command=self.prewitt)
        self.button12.grid(row=3, column=3, pady=10)

        self.button13 = Button(self.frame, text="Scharr", font=("Arial", 12), bg="white",
                                command=self.scharr)
        self.button13.grid(row=4, column=0, pady=10)

        self.button14 = Button(self.frame, text="Kirsh", font=("Arial", 12), bg="white",
                                command=self.kirsh)
        self.button14.grid(row=4, column=1, pady=10)

        self.button15 = Button(self.frame, text="Gradient", font=("Arial", 12), bg="white",
                                command=self.gradient)
        self.button15.grid(row=4, column=2, pady=10)

        self.button16 = Button(self.frame, text="Top hat", font=("Arial", 12), bg="white",
                                command=self.top_hat)
        self.button16.grid(row=4, column=3, pady=10)

        self.button17 = Button(self.frame, text="Black hat", font=("Arial", 12), bg="white",
                                command=self.black_hat)
        self.button17.grid(row=5, column=0, pady=10)

        self.button18 = Button(self.frame, text="Erousion", font=("Arial", 12), bg="white",
                                command=self.erosion)
        self.button18.grid(row=5, column=1, pady=10)

        self.button19 = Button(self.frame, text="Dilation", font=("Arial", 12), bg="white",
                                command=self.dilation)
        self.button19.grid(row=5, column=2, pady=10)

        self.button20 = Button(self.frame, text="Furie", font=("Arial", 12), bg="white",
                                command=self.furie)
        self.button20.grid(row=5, column=3, pady=10)

        self.button21 = Button(self.frame, text="Vincent", font=("Arial", 12), bg="white",
                                command=self.vincent)
        self.button21.grid(row=6, column=0, pady=10)

        self.button22 = Button(self.frame, text="Shi-Tomasi", font=("Arial", 12), bg="white",
                                command=self.shi_tomasi)
        self.button22.grid(row=6, column=1, pady=10)

        self.button23 = Button(self.frame, text="Opening", font=("Arial", 12), bg="white",
                                command=self.opening)
        self.button23.grid(row=6, column=2, pady=10)

        self.button24 = Button(self.frame, text="Closing", font=("Arial", 12), bg="white",
                                command=self.closing)
        self.button24.grid(row=6, column=3, pady=10)

        self.label1 = Label(self.frame, text="Original Image", font=("Arial", 12), bg="white")
        self.label1.grid(row=10, column=0, pady=10)

        self.label2 = Label(self.frame, text="Processed Image", font=("Arial", 12), bg="white")
        self.label2.grid(row=10, column=0, pady=10)

        self.image1 = self.solution.original()
        self.label3 = Label(self.frame, image=self.image1, bg="white")
        self.label3.grid(row=8, column=0, pady=10)

        self.image2 = self.solution.original()
        self.label4 = Label(self.frame, image=self.image2, bg="white")
        self.label4.grid(row=8, column=1, pady=10)

    def original_image(self):
        self.image1 = self.solution.original()
        self.label3.configure(image=self.image1)
        self.label3.image = self.image1

    def filt(self):
        self.image2 = self.solution.filt()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def local_threshold(self):
        self.image1 = self.solution.local_threshold()
        self.label4.configure(image=self.image1)
        self.label4.image = self.image1

    def adaptive_threshold(self):
        self.image2 = self.solution.adaptive_threshold()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def gaussian_filter(self):
        self.image2 = self.solution.gaussian_filter()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def bilateral_filter(self):
        self.image2 = self.solution.bilateral_filter()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def gradient(self):
        self.image2 = self.solution.gradient()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def top_hat(self):
        self.image2 = self.solution.top_hat()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def black_hat(self):
        self.image2 = self.solution.black_hat()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def erosion(self):
        self.image2 = self.solution.erosion()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def dilation(self):
        self.image2 = self.solution.dilation()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def houk(self):
        self.image2 = self.solution.houk()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def sobel(self):
        self.image2 = self.solution.sobel()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def laplacian(self):
        self.image2 = self.solution.laplacian()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def furie(self):
        self.image2 = self.solution.furie()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def opening(self):
        self.image2 = self.solution.opening()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def closing(self):
        self.image2 = self.solution.closing()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def canny(self):
        self.image2 = self.solution.canny()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def hough(self):
        self.image2 = self.solution.hough()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def vincent(self):
        self.image2 = self.solution.vincent()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def prewitt(self):
        self.image2 = self.solution.prewitt()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def shi_tomasi(self):
        self.image2 = self.solution.shi_tomasi()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def scharr(self):
        self.image2 = self.solution.scharr()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def kirsh(self):
        self.image2 = self.solution.kirsh()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2

    def roberts(self):
        self.image2 = self.solution.roberts()
        self.label4.configure(image=self.image2)
        self.label4.image = self.image2


if __name__ == "__main__":
    root = Tk()
    root.title("Image Processing")
    root.geometry("1000x600")
    root.resizable(False, False)
    app = MainApp(root)
    root.mainloop()