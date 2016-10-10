module Result where

data Result a = Reject String | Accept a

instance Functor Result where
    fmap f (Accept a) = Accept $ f a
    fmap _ (Reject s) = Reject s

instance Applicative Result where
    pure = Accept
    Accept f <*> Accept a = Accept $ f a
    Reject s <*> _ = Reject s
    _ <*> Reject s = Reject s

instance Monad Result where
    Reject s >>= _ = Reject s
    Accept a >>= f = f a
    return = Accept
    fail = Reject

instance (Show a) => Show (Result a) where
    show (Reject s) = "Reject: " ++ s
    show (Accept a) = "Accept: " ++ show a
