#include <engine/audio/AudioEngine.hpp>
#include <engine/audio/AudioSource.hpp>

#include <gtest/gtest.h>

using namespace irrklang;

namespace gam703::engine::audio::tests
{
	class MockSound : public ISoundSource
	{
	public:
		virtual const ik_c8* getName() { return nullptr; }
		virtual void setStreamMode(E_STREAM_MODE mode) {}
		virtual E_STREAM_MODE getStreamMode() { return E_STREAM_MODE::ESM_AUTO_DETECT; }
		virtual ik_u32 	getPlayLength() { return 0; }
		virtual SAudioStreamFormat 	getAudioFormat() { return {}; }
		virtual bool getIsSeekingSupported() { return false; }
		virtual void setDefaultVolume(ik_f32 volume = 1.0f) { m_volume = volume; }
		virtual ik_f32 getDefaultVolume() { return m_volume; }
		virtual void setDefaultMinDistance(ik_f32 minDistance) {}
		virtual ik_f32 getDefaultMinDistance() { return 0; }
		virtual void setDefaultMaxDistance(ik_f32 maxDistance) {}
		virtual ik_f32 getDefaultMaxDistance() { return 0; }
		virtual void forceReloadAtNextUse() {}
		virtual void setForcedStreamingThreshold(ik_s32 thresholdBytes) {}
		virtual ik_s32 getForcedStreamingThreshold() { return 0; }
		virtual void* getSampleData() { return 0; }
		virtual bool drop() { return false; }
		virtual void grab() {}

		ik_f32 m_volume = 1;
	};

	static AudioEngine engine;

	TEST(AudioSourceTests, AudioSourceDefault)
	{
		MockSound sound;
		AudioSource source{ engine, sound };

		EXPECT_EQ(1, source.getVolume());
		EXPECT_EQ(1, source.getOutputVolume());
		EXPECT_EQ(1, sound.getDefaultVolume());
	}

	TEST(AudioSourceTests, AudioSourceChangeVolume)
	{
		MockSound sound;
		AudioSource source{ engine , sound };

		ASSERT_EQ(1, source.getVolume());
		ASSERT_EQ(1, source.getOutputVolume());
		EXPECT_EQ(1, sound.getDefaultVolume());

		source.setVolume(0.2f);

		EXPECT_EQ(0.2f, source.getVolume());
		EXPECT_EQ(0.2f, source.getOutputVolume());
		EXPECT_EQ(0.2f, sound.getDefaultVolume());
	}

	TEST(AudioSourceTests, AudioSourceMinVolume)
	{
		MockSound sound;
		AudioSource source{ engine , sound };

		ASSERT_EQ(1, source.getVolume());
		ASSERT_EQ(1, source.getOutputVolume());
		EXPECT_EQ(1, sound.getDefaultVolume());

		source.setVolume(-1);

		EXPECT_EQ(0, source.getVolume());
		EXPECT_EQ(0, source.getOutputVolume());
		EXPECT_EQ(0, sound.getDefaultVolume());
	}

	TEST(AudioSourceTests, AudioSourceMaxVolume)
	{
		MockSound sound;
		AudioSource source{ engine , sound };

		ASSERT_EQ(1, source.getVolume());
		ASSERT_EQ(1, source.getOutputVolume());
		ASSERT_EQ(1, sound.getDefaultVolume());

		source.setVolume(2);

		EXPECT_EQ(1, source.getVolume());
		EXPECT_EQ(1, source.getOutputVolume());
		EXPECT_EQ(1, sound.getDefaultVolume());
	}

	TEST(AudioMixerTests, AudioMixerDefault)
	{
		AudioMixer mixer{};

		EXPECT_EQ(1, mixer.getVolume());
		EXPECT_EQ(1, mixer.getOutputVolume());
	}

	TEST(AudioMixerTests, AudioMixerChangeVolume)
	{
		AudioMixer mixer{};

		ASSERT_EQ(1, mixer.getVolume());
		ASSERT_EQ(1, mixer.getOutputVolume());

		mixer.setVolume(0.2f);

		EXPECT_EQ(0.2f, mixer.getVolume());
		EXPECT_EQ(0.2f, mixer.getOutputVolume());
	}

	TEST(AudioMixerTests, AudioMixerMinVolume)
	{
		AudioMixer mixer{};

		ASSERT_EQ(1, mixer.getVolume());
		ASSERT_EQ(1, mixer.getOutputVolume());

		mixer.setVolume(-1);

		EXPECT_EQ(0, mixer.getVolume());
		EXPECT_EQ(0, mixer.getOutputVolume());
	}

	TEST(AudioMixerTests, AudioMixerMaxVolume)
	{
		AudioMixer mixer{};

		ASSERT_EQ(1, mixer.getVolume());
		ASSERT_EQ(1, mixer.getOutputVolume());

		mixer.setVolume(2);

		EXPECT_EQ(1, mixer.getVolume());
		EXPECT_EQ(1, mixer.getOutputVolume());
	}

	TEST(AudioMixerIntegration, OneAudioMixer)
	{
		MockSound sound;
		AudioSource source{ engine, sound };
		AudioMixer mixer{};

		mixer.setVolume(0.5f);

		ASSERT_EQ(1, source.getVolume());
		ASSERT_EQ(1, source.getOutputVolume());
		ASSERT_EQ(1, sound.getDefaultVolume());
		ASSERT_EQ(0.5f, mixer.getVolume());
		ASSERT_EQ(0.5f, mixer.getOutputVolume());

		source.setAudioMixer(&mixer);

		EXPECT_EQ(1, source.getVolume());
		EXPECT_EQ(0.5f, source.getOutputVolume());
		EXPECT_EQ(0.5f, sound.getDefaultVolume());
		EXPECT_EQ(0.5f, mixer.getVolume());
		EXPECT_EQ(0.5f, mixer.getOutputVolume());

		source.setVolume(0.5f);

		EXPECT_EQ(0.5f, source.getVolume());
		EXPECT_EQ(0.25f, source.getOutputVolume());
		EXPECT_EQ(0.25f, sound.getDefaultVolume());
		EXPECT_EQ(0.5f, mixer.getVolume());
		EXPECT_EQ(0.5f, mixer.getOutputVolume());

		source.setAudioMixer(nullptr);

		EXPECT_EQ(0.5f, source.getVolume());
		EXPECT_EQ(0.5f, source.getOutputVolume());
		EXPECT_EQ(0.5f, sound.getDefaultVolume());
		EXPECT_EQ(0.5f, mixer.getVolume());
		EXPECT_EQ(0.5f, mixer.getOutputVolume());
	}

	TEST(AudioMixerIntegration, TwoAudioMixer)
	{
		MockSound sound;
		AudioSource source{ engine, sound };
		AudioMixer child{};
		AudioMixer master{};

		master.setVolume(0.5f);

		child.setParentMixer(&master);
		child.setVolume(0.5f);

		ASSERT_EQ(1, source.getVolume());
		ASSERT_EQ(1, source.getOutputVolume());
		ASSERT_EQ(1, sound.getDefaultVolume());
		ASSERT_EQ(0.5f, master.getVolume());
		ASSERT_EQ(0.5f, master.getOutputVolume());
		ASSERT_EQ(0.5f, child.getVolume());
		ASSERT_EQ(0.25f, child.getOutputVolume());

		source.setAudioMixer(&child);

		EXPECT_EQ(1, source.getVolume());
		EXPECT_EQ(0.25f, source.getOutputVolume());
		EXPECT_EQ(0.25f, sound.getDefaultVolume());
		EXPECT_EQ(0.5f, child.getVolume());
		EXPECT_EQ(0.25f, child.getOutputVolume());
		EXPECT_EQ(0.5f, master.getVolume());
		EXPECT_EQ(0.5f, master.getOutputVolume());

		source.setVolume(0.5f);

		EXPECT_EQ(0.5f, source.getVolume());
		EXPECT_EQ(0.125f, source.getOutputVolume());
		EXPECT_EQ(0.125f, sound.getDefaultVolume());
		EXPECT_EQ(0.5f, child.getVolume());
		EXPECT_EQ(0.25f, child.getOutputVolume());
		EXPECT_EQ(0.5f, master.getVolume());
		EXPECT_EQ(0.5f, master.getOutputVolume());

		child.setParentMixer(nullptr);

		EXPECT_EQ(0.5f, source.getVolume());
		EXPECT_EQ(0.25f, source.getOutputVolume());
		EXPECT_EQ(0.25f, sound.getDefaultVolume());
		EXPECT_EQ(0.5f, child.getVolume());
		EXPECT_EQ(0.5f, child.getOutputVolume());
		EXPECT_EQ(0.5f, master.getVolume());
		EXPECT_EQ(0.5f, master.getOutputVolume());

		source.setAudioMixer(nullptr);

		EXPECT_EQ(0.5f, source.getVolume());
		EXPECT_EQ(0.5f, source.getOutputVolume());
		EXPECT_EQ(0.5f, sound.getDefaultVolume());
		EXPECT_EQ(0.5f, child.getVolume());
		EXPECT_EQ(0.5f, child.getOutputVolume());
		EXPECT_EQ(0.5f, master.getVolume());
		EXPECT_EQ(0.5f, master.getOutputVolume());
	}
}
