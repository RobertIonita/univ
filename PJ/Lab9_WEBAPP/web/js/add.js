// Wait for the DOM to be loaded
document.addEventListener('DOMContentLoaded', function () {
    let datePickers = document.querySelectorAll('.datepicker'),
        date = new Date(),
        datePickerOptions = {
            "maxDate": date,
            "yearRange": [date.getFullYear() - 120, date.getFullYear()],
            "firstDay": 1,
            "i18n": {
                "months": [
                    'Ianuarie',
                    'Februarie',
                    'Martie',
                    'Aprile',
                    'Mai',
                    'Iunie',
                    'Iulie',
                    'August',
                    'Septembrie',
                    'Octombrie',
                    'Noviembrie',
                    'Decembrie'
                ],
                "weekdaysShort": [
                    'Dum',
                    'Lun',
                    'Mar',
                    'Mie',
                    'Joi',
                    'Vin',
                    'Sâm'
                ],
                "weekdays": [
                    'Duminică',
                    'Luni',
                    'Marți',
                    'Miercuri',
                    'Joi',
                    'Vineri',
                    'Sâmbătă'
                ],
                "weekdaysAbbrev": ['D','L','M','M','J','V','S'],
                "cancel": 'Renunță'
            }
        };
    M.Datepicker.init(datePickers, datePickerOptions);
});

