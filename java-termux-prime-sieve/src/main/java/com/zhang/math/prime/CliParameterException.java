package com.zhang.math.prime;

public class CliParameterException extends RuntimeException {
    public static final long serialVersionUID = 1L;

    public CliParameterException() {
        super();
    }

    public CliParameterException(String message) {
        super(message);
    }

    public CliParameterException(String message, Throwable cause) {
        super(message, cause);
    }

    public CliParameterException(Throwable cause) {
        super(cause);
    }
}
