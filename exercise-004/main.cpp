#include <fmt/chrono.h>
#include <fmt/format.h>
#include <filesystem>

#include <opencv2/opencv.hpp>
#include "CLI/CLI.hpp"
#include "config.h.in"
#include "image.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    int image_size = sizeof(image)/sizeof(image[0]);

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */

    // Aufgabe 3:
    fmt::print("Hello, {}!\n", app.get_name());
    fmt::println("Höhe: {}", image_height);
    fmt::println("Breite: {}", image_width);
    fmt::println("Bildgröße: {} Bytes", image_size);
    
    // Aufgabe 5:
    cv::Mat img(image_height, image_width, CV_8UC3, (void*)image);
    fmt::print("Breite: {}\nHöhe: {}\nKanäle: {}\n", img.cols, img.rows, img.channels());

    // Aufgabe 6:
    cv::Mat gray, blurred, edges;

    // 1. Graustufen
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    fmt::print("Graustufenbild: Größe = {}x{}, Kanäle = {}\n", gray.cols, gray.rows, gray.channels());

    // 2. Gaussian Blur mit Kernelgröße 7x7, Sigma 1.5
    int ksize = 71;
    double sigma = 1;
    cv::GaussianBlur(gray, blurred, cv::Size(ksize, ksize), sigma);
    fmt::print("Gaussian Blur: Kernelgröße = {}x{}, Sigma = {:.2f}\n", ksize, ksize, sigma);

    // 3. Canny Kantenfilter mit Thresholds 50 und 150
    double threshold1 = 50;
    double threshold2 = 150;
    cv::Canny(blurred, edges, threshold1, threshold2);
    fmt::print("Canny Kantenfilter: threshold1 = {}, threshold2 = {}, Kanten Pixelanzahl = {}\n",
            threshold1, threshold2, cv::countNonZero(edges));

    //Aufgabe 7: Bilder speichern
        
    // Standardwerte aus config.h.in (z.B. DEFAULT_OUTPUT_PATH, DEFAULT_OUTPUT_FILENAME)
    std::string output_path = DEFAULT_OUTPUT_PATH;
    std::string output_filename = DEFAULT_OUTPUT_FILENAME;

    // CLI-Parameter für Pfad und Dateiname hinzufügen
    app.add_option("-o,--output-path", output_path, "Speicherort für das Bild");
    app.add_option("-f,--filename", output_filename, "Dateiname für das Bild");

    // Nach dem Parsen (ist im oberen Programmteil schon erledigt)

    std::string savedfile = fmt::format("{}/{}", output_path, output_filename);
    
    // Erstellung des Ordners
    std::filesystem::create_directories(output_path); // output_path

    // Zum Beispiel speichern wir das Kantenbild ("edges") aus Aufgabe 6
    if (cv::imwrite(savedfile, blurred)) {
        fmt::print("Bild erfolgreich gespeichert als: {}\n", savedfile);

        // Nach dem Speichern: Dateigröße ermitteln
        std::ifstream file(savedfile, std::ios::binary | std::ios::ate);
        if (file) {
            std::streamsize output_size = file.tellg();
            file.close();

            fmt::print("Gespeicherte Dateigröße: {} Bytes\n", output_size);

            // Optional: Vergleich Originalgröße <-> Ausgabebild
            fmt::print("Originalgröße (Embedded): {} Bytes\n", image_size);
            fmt::print("Größenverhältnis: {:.2f} %\n", 100.0 * output_size / image_size);
        } else {
            fmt::print("Konnte gespeicherte Datei nicht öffnen!\n");
        }
    } else {
        fmt::print("Fehler beim Speichern von {}\n", savedfile);
    }

    return 0; /* exit gracefully*/
}
