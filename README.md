# Visible For Testing PHP Extension

This PHP extension provides functionality similar to Java's `@VisibleForTesting` annotation, allowing certain private methods to be accessible during testing.

## Requirements

- PHP 7.4 or higher
- php-dev package
- build-essential package (on Ubuntu/Debian)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/visible-for-testing-php.git
   cd visible-for-testing-php
   ```

2. Prepare the build environment:
   ```bash
   phpize
   ```

3. Configure the build:
   ```bash
   ./configure --enable-visible_for_testing
   ```

4. Compile the extension:
   ```bash
   make
   ```

5. Install the extension:
   ```bash
   sudo make install
   ```

6. Enable the extension by adding the following line to your php.ini file:
   ```ini
   extension=visible_for_testing.so
   ```

7. Restart your web server if you're using one (e.g., Apache, Nginx).

## Usage

```php
ini_set('visible_for_testing.testing_mode', '1'); // Enable testing mode

class YourClass
{
    #[VisibleForTesting]
    private function testMethod(): string
    {
        return "Test method called";
    }
}

$instance = new YourClass();
echo $instance->testMethod(); // "Test method called"

ini_set('visible_for_testing.testing_mode', '0'); // Disable testing mode
```

## Running Tests

To run the extension tests:

```bash
php run-tests.php
```

## Cleaning Up

To clean the build files:

```bash
make clean
phpize --clean
```

## Troubleshooting

If you encounter any issues during the build process, you can try the following:

1. Ensure you have the necessary development tools installed:
   ```bash
   sudo apt-get install php-dev build-essential autoconf automake libtool
   ```

2. If `phpize` is not found, locate it using:
   ```bash
   which phpize
   ```
   If it's not in your PATH, you may need to specify the full path or add it to your PATH.

3. Check PHP version and ensure compatibility:
   ```bash
   php -v
   ```

4. If you're using a specific PHP version, you might need to use the corresponding phpize:
   ```bash
   phpize7.4  # for PHP 7.4
   ```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.