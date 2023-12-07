//
// Created by aliye on 4/24/2023.
//

#include "wearherView.h"


void wearherView::WeatherInterface(std::string city, int days) {
    weatherdata weather_info;

    weather_info.get_weather_data_information(city, 16);
    int weather_days;
    weather_days = days * 4;
    std::cout << "weather in: " << city << "\n";
    for (int i = 0; i < weather_days; i += 4) {
        auto document =
            ftxui::window(
                ftxui::text(weather_info.get_weather_time()[i].substr(0, 10)) | ftxui::hcenter | ftxui::flex,
                ftxui::hbox({ftxui::vbox({ftxui::text("Night") | ftxui::hcenter, ftxui::separator(),
                                          ForecastPicture(weather_info.get_weather_code()[i]),
                                          align_right(ftxui::text(
                                              "temp_2m: " + weather_info.get_temp_2m()[i] + " °C\\n")),
                                          align_right(ftxui::text(
                                              "relative_humid: " + weather_info.get_relative_humidity()[i])),
                                          align_right(ftxui::text(
                                              "wind_speed: " + weather_info.get_wind_speed()[i] + " m/s\n")),
                                          align_right(ftxui::text(
                                              "wind_direction: " + weather_info.get_wind_direction()[i]))})
                                 | ftxui::border | ftxui::flex,
                             ftxui::vbox(ftxui::text("Morning") | ftxui::hcenter, ftxui::separator(),
                                         ForecastPicture(weather_info.get_weather_code()[i + 1]),
                                         align_right(ftxui::text(
                                             "temp_2m: " + weather_info.get_temp_2m()[i + 1] + " °C\\n")),
                                         align_right(ftxui::text("relative_humid: "
                                                                     + weather_info.get_relative_humidity()[i
                                                                         + 1])),
                                         align_right(ftxui::text(
                                             "wind_speed: " + weather_info.get_wind_speed()[i + 1]
                                                 + " m/s\n")),
                                         align_right(ftxui::text(
                                             "wind_direction: " + weather_info.get_wind_direction()[i + 1])))
                                 | ftxui::border | ftxui::flex,
                             ftxui::vbox(ftxui::text("Day") | ftxui::hcenter, ftxui::separator(),
                                         ForecastPicture(weather_info.get_weather_code()[i + 2]),
                                         align_right(ftxui::text(
                                             "temp_2m: " + weather_info.get_temp_2m()[i + 2] + " °C\\n")),
                                         align_right(ftxui::text("relative_humid: "
                                                                     + weather_info.get_relative_humidity()[i
                                                                         + 2])),
                                         align_right(ftxui::text(
                                             "wind_speed: " + weather_info.get_wind_speed()[i + 2]
                                                 + " m/s\n")),
                                         align_right(ftxui::text(
                                             "wind_direction: " + weather_info.get_wind_direction()[i + 2])))
                                 | ftxui::border | ftxui::flex,
                             ftxui::vbox(ftxui::text("Evening") | ftxui::hcenter, ftxui::separator(),
                                         ForecastPicture(weather_info.get_weather_code()[i + 3]),
                                         align_right(ftxui::text(
                                             "temp_2m: " + weather_info.get_temp_2m()[i + 3] + " °C\\n")),
                                         align_right(ftxui::text("relative_humid: "
                                                                     + weather_info.get_relative_humidity()[i
                                                                         + 3])),
                                         align_right(ftxui::text(
                                             "wind_speed: " + weather_info.get_wind_speed()[i + 3])),
                                         align_right(ftxui::text(
                                             "wind_direction: " + weather_info.get_wind_direction()[i + 3])))
                                 | ftxui::border | ftxui::flex}));
        auto col = ftxui::color(ftxui::Color::Palette16::Green, document);
        auto screen = ftxui::Screen::Create(
            ftxui::Dimension::Full(),
            ftxui::Dimension::Fit(document)
        );
        ftxui::Render(screen, document);
        screen.Print();
    }
}

void wearherView::DO_YOU_HAVE_THE_BEST_WEATHER(std::string city) {
    weatherdata weatherdata;
    weatherdata.get_weather_data_information(city, 10);
    double weather_mid = 0;
    for(int i = 0; i < weatherdata.get_temp_2m().size(); i++) {
        weather_mid += std::stoi(weatherdata.get_temp_2m()[i]);
    }

    std::string weather_str = std::to_string(weather_mid / weatherdata.get_temp_2m().size());
    auto doc = ftxui::hbox(ftxui::text(city + ": " + weather_str) | ftxui::flex);
    auto screen = ftxui::Screen::Create(
        ftxui::Dimension::Full(),
        ftxui::Dimension::Fit(doc)
    );
    ftxui::Render(screen, doc);
    screen.Print();
}

