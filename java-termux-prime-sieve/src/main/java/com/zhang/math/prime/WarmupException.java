package com.zhang.math.prime;

public class WarmupException extends RuntimeException {
    public static final long serialVersionUID = 1L;

    public WarmupException() {
        super();
    }

    public WarmupException(String message) {
        super(message);
    }

    public WarmupException(String message, Throwable cause) {
        super(message, cause);
    }

    public WarmupException(Throwable cause) {
        super(cause);
    }
}
