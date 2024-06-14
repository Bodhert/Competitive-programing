defmodule PaintByNumber do
  def palette_bit_size(color_count) do
    calculate_palet_size(color_count, 1)
  end

  defp calculate_palet_size(number, exponent) do
    power = Integer.pow(2, exponent)
    remainder = number - power

    cond do
      remainder > 0 -> calculate_palet_size(number, exponent + 1)
      true -> exponent
    end
  end

  def empty_picture() do
    <<>>
  end

  def test_picture() do
    <<0::2, 1::2, 2::2, 3::2>>
  end

  def prepend_pixel(picture, color_count, pixel_color_index) do
    <<pixel_color_index::size(palette_bit_size(color_count)), picture::bitstring>>
  end

  def get_first_pixel(<<>>, _), do: nil

  def get_first_pixel(picture, color_count) do
    size = palette_bit_size(color_count)
    <<first_pixel::size(size), _rest::bitstring>> = picture
    first_pixel
  end

  def drop_first_pixel(<<>>, _), do: <<>>

  def drop_first_pixel(picture, color_count) do
    size = palette_bit_size(color_count)
    <<_first_pixel::size(size), rest::bitstring>> = picture
    rest
  end

  def concat_pictures(picture1, picture2) do
    <<picture1::bitstring, picture2::bitstring>>
  end
end
