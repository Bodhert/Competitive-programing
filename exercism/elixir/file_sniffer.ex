defmodule FileSniffer do
  
  @exe_extensions <<0x7F, 0x45, 0x4C, 0x46>>
  @bpm_extensions <<0x42, 0x4D>>
  @png_extensions <<0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A>>
  @jpg_extensions <<0xFF, 0xD8, 0xFF>>
  @gif_extensions <<0x47, 0x49, 0x46>>

  @spec type_from_extension(String.t()) :: (String.t())
  def type_from_extension("exe"), do: "application/octet-stream"
  def type_from_extension("bmp"), do: "image/bmp"
  def type_from_extension("png"), do: "image/png"
  def type_from_extension("jpg"), do: "image/jpg"
  def type_from_extension("gif"), do: "image/gif"

  @spec type_from_binary(binary()) :: String.t()
  def type_from_binary(<<@exe_extensions, _rest::binary>>), do: type_from_extension("exe")
  def type_from_binary(<<@bpm_extensions, _rest::binary>>), do: type_from_extension("bmp")
  def type_from_binary(<<@gif_extensions, _rest::binary>>), do: type_from_extension("gif")
  def type_from_binary(<<@png_extensions, _rest::binary>>), do: type_from_extension("png")
  def type_from_binary(<<@jpg_extensions, _rest::binary>>), do: type_from_extension("jpg")

  @spec verify(binary(), String.t()) :: {:ok, String.t()} | {:error, String.t()}
  def verify(file_binary, extension) do
    binary_format = type_from_binary(file_binary)
    case type_from_extension(extension) do
      ^binary_format -> {:ok, binary_format}
      _              -> {:error, "Warning, file format and file extension do not match."}
    end
  end

end
